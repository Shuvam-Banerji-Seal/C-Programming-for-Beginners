/*
 * defensive_programming.c
 * Demonstrates defensive programming techniques in C
 *
 * Topics: assert, input validation, bounds checking, NULL guards,
 *         safe string operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

/* ============================================================================
 * SECTION 1: assert() for Development Checks
 *
 * assert() verifies conditions that should ALWAYS be true if the code is
 * correct. It is a development tool, not a runtime error handler.
 *
 * - Use assert for programmer errors (bugs), not for user input errors.
 * - Assertions are removed when compiling with -DNDEBUG (release builds).
 * ============================================================================ */

/*
 * factorial - Computes n! for non-negative integers.
 *
 * The assert guards against misuse by the programmer.
 * A negative input here would indicate a bug in the calling code.
 */
unsigned long factorial(int n) {
    assert(n >= 0 && "factorial: n must be non-negative");
    assert(n <= 20 && "factorial: n too large, would overflow");

    unsigned long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= (unsigned long)i;
    }
    return result;
}

/*
 * array_get - Retrieves an element from an array with an assertion
 * on the index. This catches out-of-bounds access during development.
 */
int array_get(const int *arr, size_t size, size_t index) {
    assert(arr != NULL && "array_get: array pointer must not be NULL");
    assert(index < size && "array_get: index out of bounds");
    return arr[index];
}

void demonstrate_assert(void) {
    printf("=== 1. assert() for Development Checks ===\n\n");

    printf("  factorial(5) = %lu\n", factorial(5));
    printf("  factorial(10) = %lu\n", factorial(10));
    printf("  factorial(0) = %lu\n", factorial(0));

    int data[] = {10, 20, 30, 40, 50};
    size_t data_size = sizeof(data) / sizeof(data[0]);

    printf("  array_get(data, 5, 2) = %d\n", array_get(data, data_size, 2));
    printf("  array_get(data, 5, 4) = %d\n", array_get(data, data_size, 4));

    /*
     * These would trigger assertions if uncommented:
     *   factorial(-1);            // negative input
     *   array_get(data, 5, 10);   // out of bounds
     *   array_get(NULL, 5, 0);    // NULL pointer
     */

    printf("  (Assertions passed -- all inputs were valid)\n\n");
}

/* ============================================================================
 * SECTION 2: Input Validation Functions
 *
 * User input and external data must always be validated before use.
 * Unlike assert (which catches bugs), validation handles expected bad input.
 * ============================================================================ */

/* Validation result codes */
#define VALID           0
#define INVALID_NULL    1
#define INVALID_EMPTY   2
#define INVALID_LENGTH  3
#define INVALID_CHARS   4
#define INVALID_RANGE   5

/*
 * validate_username - Checks that a username meets requirements:
 *   - Not NULL
 *   - Between 3 and 31 characters
 *   - Contains only alphanumeric characters and underscores
 *
 * Returns VALID (0) on success, or an error code describing the problem.
 */
int validate_username(const char *username) {
    if (username == NULL) {
        return INVALID_NULL;
    }

    size_t len = strlen(username);
    if (len == 0) {
        return INVALID_EMPTY;
    }
    if (len < 3 || len > 31) {
        return INVALID_LENGTH;
    }

    for (size_t i = 0; i < len; i++) {
        if (!isalnum((unsigned char)username[i]) && username[i] != '_') {
            return INVALID_CHARS;
        }
    }

    return VALID;
}

/*
 * validate_age - Checks that age is within a reasonable range.
 */
int validate_age(int age) {
    if (age < 0 || age > 150) {
        return INVALID_RANGE;
    }
    return VALID;
}

const char *validation_error_string(int code) {
    switch (code) {
        case VALID:          return "Valid";
        case INVALID_NULL:   return "Input is NULL";
        case INVALID_EMPTY:  return "Input is empty";
        case INVALID_LENGTH: return "Invalid length";
        case INVALID_CHARS:  return "Contains invalid characters";
        case INVALID_RANGE:  return "Value out of range";
        default:             return "Unknown validation error";
    }
}

void demonstrate_input_validation(void) {
    printf("=== 2. Input Validation ===\n\n");

    /* Test various usernames */
    const char *usernames[] = {
        "alice_42",
        "ab",
        "",
        NULL,
        "bad user!",
        "good_name_123"
    };
    /* Display names for printing (since some are NULL) */
    const char *display[] = {
        "\"alice_42\"",
        "\"ab\"",
        "\"\"",
        "NULL",
        "\"bad user!\"",
        "\"good_name_123\""
    };
    size_t num_tests = sizeof(usernames) / sizeof(usernames[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int result = validate_username(usernames[i]);
        printf("  validate_username(%-16s) -> %s\n",
               display[i], validation_error_string(result));
    }

    printf("\n");

    /* Test age validation */
    int ages[] = {25, -1, 0, 150, 200};
    size_t num_ages = sizeof(ages) / sizeof(ages[0]);

    for (size_t i = 0; i < num_ages; i++) {
        int result = validate_age(ages[i]);
        printf("  validate_age(%3d) -> %s\n",
               ages[i], validation_error_string(result));
    }

    printf("\n");
}

/* ============================================================================
 * SECTION 3: Bounds Checking for Arrays
 *
 * C does not perform automatic bounds checking. Off-by-one errors and
 * buffer overflows are among the most common and dangerous bugs in C.
 * ============================================================================ */

/*
 * SafeArray - A simple wrapper that tracks array size alongside data.
 * This pattern prevents out-of-bounds access by always knowing the size.
 */
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} SafeArray;

/* Initialize a SafeArray with a given capacity */
SafeArray *safe_array_create(size_t capacity) {
    if (capacity == 0) {
        return NULL;
    }

    SafeArray *arr = (SafeArray *)malloc(sizeof(SafeArray));
    if (arr == NULL) {
        return NULL;
    }

    arr->data = (int *)calloc(capacity, sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

/* Free a SafeArray and its data */
void safe_array_destroy(SafeArray *arr) {
    if (arr != NULL) {
        free(arr->data);
        free(arr);
    }
}

/* Set a value at an index, with bounds checking. Returns 0 on success. */
int safe_array_set(SafeArray *arr, size_t index, int value) {
    if (arr == NULL) {
        return -1;
    }
    if (index >= arr->capacity) {
        fprintf(stderr, "  Bounds error: index %zu >= capacity %zu\n",
                index, arr->capacity);
        return -1;
    }
    arr->data[index] = value;
    if (index >= arr->size) {
        arr->size = index + 1;
    }
    return 0;
}

/* Get a value at an index, with bounds checking. Returns 0 on success. */
int safe_array_get(const SafeArray *arr, size_t index, int *out_value) {
    if (arr == NULL || out_value == NULL) {
        return -1;
    }
    if (index >= arr->size) {
        fprintf(stderr, "  Bounds error: index %zu >= size %zu\n",
                index, arr->size);
        return -1;
    }
    *out_value = arr->data[index];
    return 0;
}

void demonstrate_bounds_checking(void) {
    printf("=== 3. Bounds Checking for Arrays ===\n\n");

    SafeArray *arr = safe_array_create(5);
    if (arr == NULL) {
        printf("  Failed to create SafeArray\n\n");
        return;
    }

    /* Valid operations */
    safe_array_set(arr, 0, 100);
    safe_array_set(arr, 1, 200);
    safe_array_set(arr, 2, 300);

    int val;
    for (size_t i = 0; i < arr->size; i++) {
        if (safe_array_get(arr, i, &val) == 0) {
            printf("  arr[%zu] = %d\n", i, val);
        }
    }

    /* Out-of-bounds set -- caught by bounds check */
    printf("  Attempting out-of-bounds set (index 10, capacity 5):\n");
    int rc = safe_array_set(arr, 10, 999);
    printf("  -> safe_array_set returned %d (error)\n", rc);

    /* Out-of-bounds get */
    printf("  Attempting out-of-bounds get (index 4, size 3):\n");
    rc = safe_array_get(arr, 4, &val);
    printf("  -> safe_array_get returned %d (error)\n", rc);

    safe_array_destroy(arr);
    printf("\n");
}

/* ============================================================================
 * SECTION 4: NULL Pointer Guards
 *
 * Dereferencing a NULL pointer is undefined behavior and typically causes
 * a segmentation fault. Always check pointers before use.
 * ============================================================================ */

/*
 * safe_strlen - A NULL-safe wrapper around strlen.
 * Returns 0 for NULL strings instead of crashing.
 */
size_t safe_strlen(const char *str) {
    if (str == NULL) {
        return 0;
    }
    return strlen(str);
}

/*
 * safe_print_person - Prints person info with NULL guards on every field.
 */
typedef struct {
    const char *name;
    const char *email;
    int age;
} Person;

void safe_print_person(const Person *p) {
    if (p == NULL) {
        printf("  (NULL person)\n");
        return;
    }
    printf("  Name:  %s\n", (p->name != NULL)  ? p->name  : "(none)");
    printf("  Email: %s\n", (p->email != NULL) ? p->email : "(none)");
    printf("  Age:   %d\n", p->age);
}

void demonstrate_null_guards(void) {
    printf("=== 4. NULL Pointer Guards ===\n\n");

    /* safe_strlen handles NULL gracefully */
    printf("  safe_strlen(\"hello\") = %zu\n", safe_strlen("hello"));
    printf("  safe_strlen(NULL)    = %zu\n", safe_strlen(NULL));
    printf("  safe_strlen(\"\")      = %zu\n", safe_strlen(""));

    printf("\n");

    /* Complete person record */
    Person alice = {"Alice", "alice@example.com", 30};
    printf("  Complete record:\n");
    safe_print_person(&alice);

    printf("\n");

    /* Partial data -- some fields are NULL */
    Person incomplete = {"Bob", NULL, 25};
    printf("  Partial record (NULL email):\n");
    safe_print_person(&incomplete);

    printf("\n");

    /* NULL pointer */
    printf("  NULL person pointer:\n");
    safe_print_person(NULL);

    printf("\n");
}

/* ============================================================================
 * SECTION 5: Safe String Operations
 *
 * Buffer overflows from string functions like strcpy() and strcat() are a
 * leading cause of security vulnerabilities. Use bounded alternatives.
 * ============================================================================ */

/*
 * safe_string_copy - Copies src into dest with explicit size limit.
 * Always null-terminates the result. Returns 0 on success, -1 on truncation.
 */
int safe_string_copy(char *dest, size_t dest_size, const char *src) {
    if (dest == NULL || dest_size == 0) {
        return -1;
    }
    if (src == NULL) {
        dest[0] = '\0';
        return -1;
    }

    size_t src_len = strlen(src);
    int truncated = 0;

    if (src_len >= dest_size) {
        /* Truncation will occur */
        src_len = dest_size - 1;
        truncated = 1;
    }

    memcpy(dest, src, src_len);
    dest[src_len] = '\0';

    return truncated ? -1 : 0;
}

/*
 * safe_string_concat - Concatenates src onto dest with bounds checking.
 * Returns 0 on success, -1 if truncation occurred.
 */
int safe_string_concat(char *dest, size_t dest_size, const char *src) {
    if (dest == NULL || dest_size == 0 || src == NULL) {
        return -1;
    }

    size_t dest_len = strlen(dest);
    if (dest_len >= dest_size) {
        return -1;
    }

    size_t remaining = dest_size - dest_len - 1;
    size_t src_len = strlen(src);
    int truncated = 0;

    if (src_len > remaining) {
        src_len = remaining;
        truncated = 1;
    }

    memcpy(dest + dest_len, src, src_len);
    dest[dest_len + src_len] = '\0';

    return truncated ? -1 : 0;
}

void demonstrate_safe_strings(void) {
    printf("=== 5. Safe String Operations ===\n\n");

    /* Demonstrate safe copy */
    char small_buf[10];

    int rc = safe_string_copy(small_buf, sizeof(small_buf), "Hi");
    printf("  Copy \"Hi\" into buf[10]:    \"%s\" (rc=%d, %s)\n",
           small_buf, rc, rc == 0 ? "ok" : "truncated");

    rc = safe_string_copy(small_buf, sizeof(small_buf),
                          "This is a very long string");
    printf("  Copy long string into buf[10]: \"%s\" (rc=%d, %s)\n",
           small_buf, rc, rc == 0 ? "ok" : "truncated");

    printf("\n");

    /* Demonstrate safe concatenation */
    char buffer[20];
    safe_string_copy(buffer, sizeof(buffer), "Hello");
    printf("  Start:   \"%s\"\n", buffer);

    rc = safe_string_concat(buffer, sizeof(buffer), ", ");
    printf("  + \", \":  \"%s\" (rc=%d)\n", buffer, rc);

    rc = safe_string_concat(buffer, sizeof(buffer), "World!");
    printf("  + \"World!\": \"%s\" (rc=%d)\n", buffer, rc);

    rc = safe_string_concat(buffer, sizeof(buffer),
                            " This will be truncated");
    printf("  + long:  \"%s\" (rc=%d, %s)\n",
           buffer, rc, rc == 0 ? "ok" : "truncated");

    printf("\n");

    /* Demonstrate snprintf -- the standard safe formatting function */
    printf("  Using snprintf() for safe formatting:\n");
    char msg[30];
    int written = snprintf(msg, sizeof(msg),
                           "Score: %d/%d (%.1f%%)", 85, 100, 85.0);
    printf("  snprintf -> \"%s\"\n", msg);
    printf("  Would need %d chars (buffer is %zu)\n",
           written, sizeof(msg));

    printf("\n");

    /* Edge-case tests for safe_string_copy and safe_string_concat */
    printf("  Edge-case tests:\n");
    char tiny[1];
    rc = safe_string_copy(tiny, sizeof(tiny), "x");
    printf("  Copy \"x\" into buf[1]:      \"%s\" (rc=%d, %s)\n",
           tiny, rc, rc == 0 ? "ok" : "truncated");

    rc = safe_string_copy(NULL, 10, "test");
    printf("  Copy into NULL dest:       rc=%d (expected -1)\n", rc);

    char exact[6];
    rc = safe_string_copy(exact, sizeof(exact), "Hello");
    printf("  Copy \"Hello\" into buf[6]:  \"%s\" (rc=%d, %s)\n",
           exact, rc, rc == 0 ? "ok" : "truncated");

    char cat_buf[6];
    safe_string_copy(cat_buf, sizeof(cat_buf), "Hello");
    rc = safe_string_concat(cat_buf, sizeof(cat_buf), "!");
    printf("  Concat \"!\" to full buf[6]: \"%s\" (rc=%d, %s)\n",
           cat_buf, rc, rc == 0 ? "ok" : "truncated");

    rc = safe_string_copy(small_buf, 0, "test");
    printf("  Copy into zero-size buf:   rc=%d (expected -1)\n", rc);

    printf("\n");
}

/* ============================================================================
 * MAIN
 * ============================================================================ */

int main(void) {
    printf("=== Defensive Programming in C - Demonstration ===\n\n");

    demonstrate_assert();
    demonstrate_input_validation();
    demonstrate_bounds_checking();
    demonstrate_null_guards();
    demonstrate_safe_strings();

    printf("=== All demonstrations completed successfully ===\n");
    return 0;
}
