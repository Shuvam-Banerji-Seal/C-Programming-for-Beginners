/*
 * error_handling.c
 * Demonstrates error handling strategies in C
 *
 * Topics: errno, perror, strerror, return codes, error propagation,
 *         file I/O errors, memory allocation errors
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

/* ============================================================================
 * SECTION 1: Return Code Conventions
 *
 * In C, functions typically return 0 for success and non-zero for errors.
 * Negative values or specific error codes can indicate different failures.
 * ============================================================================ */

/* Error codes for our custom operations */
#define SUCCESS          0
#define ERR_NULL_PTR    -1
#define ERR_OUT_OF_RANGE -2
#define ERR_OVERFLOW    -3

/*
 * safe_divide - Performs division with error checking.
 *
 * Returns: SUCCESS on success, or a negative error code on failure.
 * The result is written through the output pointer.
 */
int safe_divide(int numerator, int denominator, int *result) {
    if (result == NULL) {
        return ERR_NULL_PTR;
    }
    if (denominator == 0) {
        return ERR_OUT_OF_RANGE;
    }
    /* Check for overflow: INT_MIN / -1 overflows in two's complement
     * because -INT_MIN cannot be represented as a signed int.
     * For example on a 32-bit system, INT_MIN is -2147483648 and the
     * maximum positive value is 2147483647, so the result wraps around. */
    if (numerator == INT_MIN && denominator == -1) {
        return ERR_OVERFLOW;
    }
    *result = numerator / denominator;
    return SUCCESS;
}

/*
 * error_code_to_string - Converts our custom error codes to human-readable
 * messages. This pattern is common in C libraries.
 */
const char *error_code_to_string(int error_code) {
    switch (error_code) {
        case SUCCESS:          return "Success";
        case ERR_NULL_PTR:     return "Null pointer argument";
        case ERR_OUT_OF_RANGE: return "Value out of range";
        case ERR_OVERFLOW:     return "Integer overflow";
        default:               return "Unknown error";
    }
}

void demonstrate_return_codes(void) {
    printf("=== 1. Return Code Conventions ===\n\n");

    int result;
    int rc;

    /* Successful division */
    rc = safe_divide(10, 3, &result);
    if (rc == SUCCESS) {
        printf("  10 / 3 = %d\n", result);
    } else {
        printf("  Error: %s\n", error_code_to_string(rc));
    }

    /* Division by zero */
    rc = safe_divide(10, 0, &result);
    if (rc != SUCCESS) {
        printf("  10 / 0 -> Error: %s (code %d)\n",
               error_code_to_string(rc), rc);
    }

    /* Null pointer */
    rc = safe_divide(10, 2, NULL);
    if (rc != SUCCESS) {
        printf("  NULL result -> Error: %s (code %d)\n",
               error_code_to_string(rc), rc);
    }

    /* Overflow case */
    rc = safe_divide(INT_MIN, -1, &result);
    if (rc != SUCCESS) {
        printf("  INT_MIN / -1 -> Error: %s (code %d)\n",
               error_code_to_string(rc), rc);
    }

    printf("\n");
}

/* ============================================================================
 * SECTION 2: errno and perror()
 *
 * errno is a global variable set by system calls and library functions
 * when an error occurs. perror() prints a descriptive error message.
 * strerror() returns the error string for a given errno value.
 * ============================================================================ */

void demonstrate_errno_and_perror(void) {
    printf("=== 2. errno, perror(), and strerror() ===\n\n");

    /*
     * Important: Always set errno to 0 before a call if you plan
     * to check it afterward. Some functions don't clear errno on success.
     */
    errno = 0;

    /* Attempt to open a file that does not exist */
    FILE *fp = fopen("/nonexistent/path/file.txt", "r");
    if (fp == NULL) {
        /* perror() prints: "<prefix>: <error message>" to stderr */
        printf("  fopen() failed. errno = %d\n", errno);
        printf("  strerror(errno) = \"%s\"\n", strerror(errno));
        perror("  perror output");
    } else {
        fclose(fp);
    }

    printf("\n");

    /* Demonstrate strtol with range error */
    errno = 0;
    const char *huge_number = "99999999999999999999999";
    char *endptr;
    long val = strtol(huge_number, &endptr, 10);
    if (errno == ERANGE) {
        printf("  strtol(\"%s\") overflowed\n", huge_number);
        printf("  Returned value: %ld (clamped to LONG_MAX or LONG_MIN)\n", val);
        printf("  strerror(ERANGE) = \"%s\"\n", strerror(ERANGE));
    }

    printf("\n");
}

/* ============================================================================
 * SECTION 3: File Operation Error Handling
 *
 * File I/O in C requires careful error checking at every step:
 * opening, reading/writing, and closing.
 * ============================================================================ */

/*
 * read_file_contents - Reads an entire file into a dynamically allocated buffer.
 *
 * On success, returns a pointer to the buffer (caller must free it).
 * On failure, returns NULL and prints a diagnostic message.
 *
 * This demonstrates the "cleanup on error" pattern using goto.
 */
char *read_file_contents(const char *filename) {
    FILE *fp = NULL;
    char *buffer = NULL;

    if (filename == NULL) {
        fprintf(stderr, "  Error: filename is NULL\n");
        return NULL;
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "  Error opening '%s': %s\n",
                filename, strerror(errno));
        return NULL;
    }

    /* Seek to end to determine file size */
    if (fseek(fp, 0, SEEK_END) != 0) {
        fprintf(stderr, "  Error seeking in '%s': %s\n",
                filename, strerror(errno));
        goto cleanup;
    }

    long file_size = ftell(fp);
    if (file_size < 0) {
        fprintf(stderr, "  Error getting size of '%s': %s\n",
                filename, strerror(errno));
        goto cleanup;
    }

    rewind(fp);

    /* Allocate buffer (+1 for null terminator) */
    buffer = (char *)malloc((size_t)file_size + 1);
    if (buffer == NULL) {
        fprintf(stderr, "  Error: malloc failed for %ld bytes\n", file_size);
        goto cleanup;
    }

    /* Read file contents */
    size_t bytes_read = fread(buffer, 1, (size_t)file_size, fp);
    if (ferror(fp)) {
        fprintf(stderr, "  Error reading '%s': %s\n",
                filename, strerror(errno));
        free(buffer);
        buffer = NULL;
        goto cleanup;
    }

    buffer[bytes_read] = '\0';

cleanup:
    if (fp != NULL) {
        fclose(fp);
    }
    return buffer;
}

void demonstrate_file_error_handling(void) {
    printf("=== 3. File Operation Error Handling ===\n\n");

    /* Try to read a nonexistent file */
    printf("  Attempting to read nonexistent file:\n");
    char *contents = read_file_contents("/tmp/nonexistent_file_12345.txt");
    if (contents == NULL) {
        printf("  -> read_file_contents returned NULL (as expected)\n");
    } else {
        free(contents);
    }

    printf("\n");

    /* Create a temporary file, write to it, read it back */
    printf("  Creating and reading a temporary file:\n");

    const char *tmpfile_path = "/tmp/error_handling_demo.txt";
    FILE *fp = fopen(tmpfile_path, "w");
    if (fp == NULL) {
        fprintf(stderr, "  Could not create temp file: %s\n", strerror(errno));
        return;
    }
    fprintf(fp, "Hello from error_handling.c\n");
    if (fclose(fp) != 0) {
        fprintf(stderr, "  Warning: fclose failed: %s\n", strerror(errno));
    }

    contents = read_file_contents(tmpfile_path);
    if (contents != NULL) {
        printf("  File contents: %s", contents);
        free(contents);
    }

    /* Clean up the temp file */
    remove(tmpfile_path);

    printf("\n");
}

/* ============================================================================
 * SECTION 4: Memory Allocation Error Handling
 *
 * malloc(), calloc(), and realloc() return NULL on failure.
 * Always check the return value before using the pointer.
 * ============================================================================ */

/*
 * create_int_array - Allocates and initializes an array of integers.
 *
 * Returns a pointer to the array, or NULL on failure.
 * Demonstrates proper realloc error handling (preserving the original pointer).
 */
int *create_int_array(size_t count) {
    if (count == 0) {
        fprintf(stderr, "  Error: cannot create array of size 0\n");
        return NULL;
    }

    int *arr = (int *)calloc(count, sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "  Error: calloc failed for %zu elements\n", count);
        return NULL;
    }

    for (size_t i = 0; i < count; i++) {
        arr[i] = (int)(i * 10);
    }

    return arr;
}

/*
 * resize_int_array - Safely resizes an integer array using realloc.
 *
 * On failure, the original array is preserved and NULL is returned.
 */
int *resize_int_array(int *arr, size_t old_count, size_t new_count) {
    if (new_count == 0) {
        free(arr);
        return NULL;
    }

    /*
     * Critical: use a temporary pointer for realloc.
     * If realloc fails and we assigned directly to arr,
     * we would lose the original pointer and leak memory.
     */
    int *temp = (int *)realloc(arr, new_count * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "  Error: realloc failed for %zu elements\n", new_count);
        /* arr is still valid; caller can decide to free it or retry */
        return NULL;
    }

    /* Initialize new elements to zero */
    for (size_t i = old_count; i < new_count; i++) {
        temp[i] = 0;
    }

    return temp;
}

void demonstrate_memory_error_handling(void) {
    printf("=== 4. Memory Allocation Error Handling ===\n\n");

    /* Normal allocation */
    size_t count = 5;
    int *arr = create_int_array(count);
    if (arr == NULL) {
        printf("  Allocation failed, skipping demo\n\n");
        return;
    }

    printf("  Created array of %zu elements: ", count);
    for (size_t i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Resize the array */
    size_t new_count = 8;
    int *resized = resize_int_array(arr, count, new_count);
    if (resized != NULL) {
        arr = resized;
        count = new_count;
        printf("  Resized to %zu elements:       ", count);
        for (size_t i = 0; i < count; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("  Resize failed, keeping original array\n");
    }

    free(arr);

    /* Demonstrate zero-size request */
    printf("  Requesting zero-size array:\n");
    int *bad = create_int_array(0);
    if (bad == NULL) {
        printf("  -> Correctly returned NULL\n");
    }

    printf("\n");
}

/* ============================================================================
 * SECTION 5: Error Propagation Pattern
 *
 * When functions call other functions, errors must be propagated upward.
 * Each layer can add context or handle the error appropriately.
 * ============================================================================ */

/* Simulates a low-level operation that may fail */
int read_sensor_value(int sensor_id, double *value) {
    if (value == NULL) {
        return ERR_NULL_PTR;
    }
    if (sensor_id < 0 || sensor_id > 9) {
        return ERR_OUT_OF_RANGE;
    }
    /* Simulate reading a value */
    *value = 23.5 + (double)sensor_id;
    return SUCCESS;
}

/* Mid-level function that processes sensor data */
int compute_average_reading(int sensor_id, int num_readings, double *average) {
    if (average == NULL) {
        return ERR_NULL_PTR;
    }
    if (num_readings <= 0) {
        return ERR_OUT_OF_RANGE;
    }

    double total = 0.0;
    for (int i = 0; i < num_readings; i++) {
        double reading;
        int rc = read_sensor_value(sensor_id, &reading);
        if (rc != SUCCESS) {
            /* Propagate the error up to the caller */
            return rc;
        }
        total += reading;
    }

    *average = total / num_readings;
    return SUCCESS;
}

void demonstrate_error_propagation(void) {
    printf("=== 5. Error Propagation ===\n\n");

    double avg;
    int rc;

    /* Successful call chain */
    rc = compute_average_reading(3, 5, &avg);
    if (rc == SUCCESS) {
        printf("  Sensor 3, 5 readings: average = %.2f\n", avg);
    } else {
        printf("  Error: %s\n", error_code_to_string(rc));
    }

    /* Error propagated from read_sensor_value */
    rc = compute_average_reading(99, 5, &avg);
    if (rc != SUCCESS) {
        printf("  Sensor 99 -> Error propagated: %s (code %d)\n",
               error_code_to_string(rc), rc);
    }

    /* Error caught at compute_average_reading level */
    rc = compute_average_reading(1, -1, &avg);
    if (rc != SUCCESS) {
        printf("  Negative readings -> Error: %s (code %d)\n",
               error_code_to_string(rc), rc);
    }

    printf("\n");
}

/* ============================================================================
 * MAIN
 * ============================================================================ */

int main(void) {
    printf("=== Error Handling in C - Demonstration ===\n\n");

    demonstrate_return_codes();
    demonstrate_errno_and_perror();
    demonstrate_file_error_handling();
    demonstrate_memory_error_handling();
    demonstrate_error_propagation();

    printf("=== All demonstrations completed successfully ===\n");
    return 0;
}
