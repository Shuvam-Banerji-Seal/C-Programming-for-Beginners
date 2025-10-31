/*
 * advanced_preprocessor.c
 * Advanced preprocessor directives and macros
 * Topics: Variadic macros, token pasting, stringification, X-macros
 */

#include <stdio.h>
#include <string.h>

// Token concatenation (##)
#define CONCAT(a, b) a##b
#define VAR_NAME(prefix, num) prefix##num

// Stringification (#)
#define TO_STRING(x) #x
#define STRINGIFY(x) TO_STRING(x)

// Variadic macros
#define PRINT_ARGS(...) printf(__VA_ARGS__)
#define DEBUG_PRINT(fmt, ...) \
    printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)

// Min/Max macros with type safety
#define MIN(a, b) ({ \
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    _a < _b ? _a : _b; \
})

#define MAX(a, b) ({ \
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    _a > _b ? _a : _b; \
})

// Macro for array size
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// Macro for loop
#define FOR_EACH(item, array, count) \
    for (int keep = 1, \
         i = 0, \
         size = count; \
         keep && i < size; \
         keep = !keep, i++) \
        for (item = array[i]; keep; keep = !keep)

// Error checking macro
#define CHECK_NULL(ptr, msg) \
    do { \
        if ((ptr) == NULL) { \
            fprintf(stderr, "Error: %s\n", msg); \
            return -1; \
        } \
    } while(0)

// X-Macro for enum and string generation
#define COLOR_TABLE \
    X(RED,     "Red") \
    X(GREEN,   "Green") \
    X(BLUE,    "Blue") \
    X(YELLOW,  "Yellow") \
    X(CYAN,    "Cyan") \
    X(MAGENTA, "Magenta")

// Generate enum
#define X(name, str) name,
typedef enum {
    COLOR_TABLE
    COLOR_COUNT
} Color;
#undef X

// Generate string array
#define X(name, str) str,
static const char* color_names[] = {
    COLOR_TABLE
};
#undef X

// Conditional compilation based on OS
#ifdef _WIN32
    #define PLATFORM "Windows"
    #define PATH_SEPARATOR '\\'
#elif defined(__linux__)
    #define PLATFORM "Linux"
    #define PATH_SEPARATOR '/'
#elif defined(__APPLE__)
    #define PLATFORM "macOS"
    #define PATH_SEPARATOR '/'
#else
    #define PLATFORM "Unknown"
    #define PATH_SEPARATOR '/'
#endif

// Conditional compilation based on compiler
#if defined(__GNUC__)
    #define COMPILER "GCC"
    #define COMPILER_VERSION __VERSION__
#elif defined(__clang__)
    #define COMPILER "Clang"
    #define COMPILER_VERSION __clang_version__
#elif defined(_MSC_VER)
    #define COMPILER "MSVC"
    #define COMPILER_VERSION STRINGIFY(_MSC_VER)
#else
    #define COMPILER "Unknown"
    #define COMPILER_VERSION "Unknown"
#endif

// Compile-time assertions
#define STATIC_ASSERT(expr, msg) \
    typedef char static_assertion_##msg[(expr) ? 1 : -1]

// Multi-line macro with do-while
#define SWAP(a, b, type) \
    do { \
        type temp = a; \
        a = b; \
        b = temp; \
    } while(0)

// Bit manipulation macros
#define SET_BIT(num, pos)    ((num) |= (1U << (pos)))
#define CLEAR_BIT(num, pos)  ((num) &= ~(1U << (pos)))
#define TOGGLE_BIT(num, pos) ((num) ^= (1U << (pos)))
#define CHECK_BIT(num, pos)  (((num) >> (pos)) & 1U)

// Function-like macro with multiple statements
#define PRINT_ARRAY(arr, size) \
    do { \
        printf("[ "); \
        for (int i = 0; i < size; i++) { \
            printf("%d ", arr[i]); \
        } \
        printf("]\n"); \
    } while(0)

// Compile-time function selection
#if defined(USE_FAST_MATH)
    #define SQRT(x) fast_sqrt(x)
#else
    #define SQRT(x) sqrt(x)
#endif

int main() {
    printf("=== Advanced Preprocessor ===\n\n");
    
    // 1. Token concatenation
    printf("1. Token Concatenation:\n");
    int VAR_NAME(test, 1) = 10;
    int VAR_NAME(test, 2) = 20;
    printf("   test1 = %d\n", test1);
    printf("   test2 = %d\n", test2);
    
    int value = CONCAT(10, 5);
    printf("   CONCAT(10, 5) = %d\n\n", value);
    
    // 2. Stringification
    printf("2. Stringification:\n");
    int my_variable = 42;
    printf("   Variable name: %s\n", TO_STRING(my_variable));
    printf("   PI value: %s\n", STRINGIFY(3.14159));
    printf("\n");
    
    // 3. Variadic macros
    printf("3. Variadic Macros:\n");
    PRINT_ARGS("   Value: %d, String: %s\n", 100, "test");
    DEBUG_PRINT("Starting process");
    DEBUG_PRINT("Processing item %d", 5);
    printf("\n");
    
    // 4. Min/Max macros
    printf("4. Min/Max Macros:\n");
    printf("   MIN(10, 20) = %d\n", MIN(10, 20));
    printf("   MAX(10, 20) = %d\n", MAX(10, 20));
    printf("   MIN(3.5, 2.8) = %.1f\n", MIN(3.5, 2.8));
    printf("\n");
    
    // 5. Array operations
    printf("5. Array Macros:\n");
    int arr[] = {1, 2, 3, 4, 5};
    printf("   Array size: %zu\n", ARRAY_SIZE(arr));
    printf("   Array: ");
    PRINT_ARRAY(arr, ARRAY_SIZE(arr));
    printf("\n");
    
    // 6. X-Macros (enum and string generation)
    printf("6. X-Macros (Enum and Strings):\n");
    for (int i = 0; i < COLOR_COUNT; i++) {
        printf("   Color %d: %s\n", i, color_names[i]);
    }
    printf("\n");
    
    // 7. Platform detection
    printf("7. Platform Detection:\n");
    printf("   Platform: %s\n", PLATFORM);
    printf("   Path separator: '%c'\n", PATH_SEPARATOR);
    printf("\n");
    
    // 8. Compiler detection
    printf("8. Compiler Detection:\n");
    printf("   Compiler: %s\n", COMPILER);
    #ifdef COMPILER_VERSION
    printf("   Version: %s\n", COMPILER_VERSION);
    #endif
    printf("\n");
    
    // 9. Predefined macros
    printf("9. Predefined Macros:\n");
    printf("   File: %s\n", __FILE__);
    printf("   Line: %d\n", __LINE__);
    printf("   Date: %s\n", __DATE__);
    printf("   Time: %s\n", __TIME__);
    #ifdef __STDC_VERSION__
    printf("   C Standard: %ld\n", __STDC_VERSION__);
    #endif
    printf("\n");
    
    // 10. Bit manipulation
    printf("10. Bit Manipulation Macros:\n");
    unsigned int flags = 0;
    printf("    Initial flags: 0x%X\n", flags);
    
    SET_BIT(flags, 2);
    printf("    After SET_BIT(2): 0x%X\n", flags);
    
    SET_BIT(flags, 5);
    printf("    After SET_BIT(5): 0x%X\n", flags);
    
    TOGGLE_BIT(flags, 2);
    printf("    After TOGGLE_BIT(2): 0x%X\n", flags);
    
    printf("    CHECK_BIT(5): %u\n", CHECK_BIT(flags, 5));
    printf("\n");
    
    // 11. Swap macro
    printf("11. Swap Macro:\n");
    int a = 10, b = 20;
    printf("    Before swap: a=%d, b=%d\n", a, b);
    SWAP(a, b, int);
    printf("    After swap: a=%d, b=%d\n", a, b);
    
    return 0;
}
