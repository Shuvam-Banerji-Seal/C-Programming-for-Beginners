/*
 * conditional_compilation.c
 * Advanced conditional compilation techniques
 * Topics: Feature flags, debug builds, optimization levels
 */

#include <stdio.h>
#include <time.h>

// Feature flags
#define FEATURE_LOGGING 1
#define FEATURE_TIMING 1
#define FEATURE_VALIDATION 1

// Debug levels
#define DEBUG_LEVEL 2  // 0=off, 1=error, 2=warning, 3=info, 4=verbose

// Conditional debug macros
#if DEBUG_LEVEL >= 1
    #define LOG_ERROR(msg) fprintf(stderr, "[ERROR] %s\n", msg)
#else
    #define LOG_ERROR(msg) ((void)0)
#endif

#if DEBUG_LEVEL >= 2
    #define LOG_WARNING(msg) fprintf(stderr, "[WARNING] %s\n", msg)
#else
    #define LOG_WARNING(msg) ((void)0)
#endif

#if DEBUG_LEVEL >= 3
    #define LOG_INFO(msg) printf("[INFO] %s\n", msg)
#else
    #define LOG_INFO(msg) ((void)0)
#endif

#if DEBUG_LEVEL >= 4
    #define LOG_VERBOSE(msg) printf("[VERBOSE] %s\n", msg)
#else
    #define LOG_VERBOSE(msg) ((void)0)
#endif

// Timing macros
#if FEATURE_TIMING
    #define START_TIMER() \
        clock_t _start_time = clock()
    
    #define END_TIMER(name) \
        do { \
            clock_t _end_time = clock(); \
            double _elapsed = ((double)(_end_time - _start_time)) / CLOCKS_PER_SEC * 1000; \
            printf("[TIMER] %s: %.2f ms\n", name, _elapsed); \
        } while(0)
#else
    #define START_TIMER() ((void)0)
    #define END_TIMER(name) ((void)0)
#endif

// Validation macros
#if FEATURE_VALIDATION
    #define VALIDATE_RANGE(val, min, max) \
        do { \
            if ((val) < (min) || (val) > (max)) { \
                fprintf(stderr, "Validation failed: %d not in range [%d, %d]\n", \
                        val, min, max); \
                return -1; \
            } \
        } while(0)
    
    #define VALIDATE_NOT_NULL(ptr) \
        do { \
            if ((ptr) == NULL) { \
                fprintf(stderr, "Validation failed: NULL pointer\n"); \
                return -1; \
            } \
        } while(0)
#else
    #define VALIDATE_RANGE(val, min, max) ((void)0)
    #define VALIDATE_NOT_NULL(ptr) ((void)0)
#endif

// Version information
#define VERSION_MAJOR 1
#define VERSION_MINOR 2
#define VERSION_PATCH 3
#define VERSION_STRING "1.2.3"

#define MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))

#define CURRENT_VERSION MAKE_VERSION(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH)

// Optimization hints
#ifdef __GNUC__
    #define LIKELY(x)   __builtin_expect(!!(x), 1)
    #define UNLIKELY(x) __builtin_expect(!!(x), 0)
    #define INLINE      __attribute__((always_inline)) inline
#else
    #define LIKELY(x)   (x)
    #define UNLIKELY(x) (x)
    #define INLINE      inline
#endif

// Configuration options
#ifdef USE_CUSTOM_ALLOCATOR
    #define MALLOC(size) custom_malloc(size)
    #define FREE(ptr) custom_free(ptr)
#else
    #include <stdlib.h>
    #define MALLOC(size) malloc(size)
    #define FREE(ptr) free(ptr)
#endif

// Architecture detection
#if defined(__x86_64__) || defined(_M_X64)
    #define ARCH "x86_64"
    #define ARCH_BITS 64
#elif defined(__i386__) || defined(_M_IX86)
    #define ARCH "x86"
    #define ARCH_BITS 32
#elif defined(__aarch64__)
    #define ARCH "ARM64"
    #define ARCH_BITS 64
#elif defined(__arm__)
    #define ARCH "ARM"
    #define ARCH_BITS 32
#else
    #define ARCH "Unknown"
    #define ARCH_BITS 0
#endif

// Sample computation function
int compute(int n) {
    LOG_INFO("Starting computation");
    
    START_TIMER();
    
    VALIDATE_RANGE(n, 1, 1000);
    
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    
    END_TIMER("Computation");
    
    return result;
}

// Function with optimization hint
INLINE int fast_multiply(int a, int b) {
    if (UNLIKELY(a == 0 || b == 0)) {
        return 0;
    }
    return a * b;
}

int main() {
    printf("=== Conditional Compilation ===\n\n");
    
    // 1. Version information
    printf("1. Version Information:\n");
    printf("   Version: %s\n", VERSION_STRING);
    printf("   Version code: %d\n", CURRENT_VERSION);
    printf("\n");
    
    // 2. Debug level
    printf("2. Debug Level: %d\n", DEBUG_LEVEL);
    LOG_ERROR("This is an error message");
    LOG_WARNING("This is a warning message");
    LOG_INFO("This is an info message");
    LOG_VERBOSE("This is a verbose message");
    printf("\n");
    
    // 3. Feature flags
    printf("3. Feature Flags:\n");
    #if FEATURE_LOGGING
    printf("   Logging: ENABLED\n");
    #else
    printf("   Logging: DISABLED\n");
    #endif
    
    #if FEATURE_TIMING
    printf("   Timing: ENABLED\n");
    #else
    printf("   Timing: DISABLED\n");
    #endif
    
    #if FEATURE_VALIDATION
    printf("   Validation: ENABLED\n");
    #else
    printf("   Validation: DISABLED\n");
    #endif
    printf("\n");
    
    // 4. Architecture detection
    printf("4. Architecture:\n");
    printf("   CPU: %s\n", ARCH);
    printf("   Bits: %d\n", ARCH_BITS);
    printf("\n");
    
    // 5. Compiler features
    printf("5. Compiler Features:\n");
    #ifdef __GNUC__
    printf("   GCC extensions: AVAILABLE\n");
    printf("   Builtin expect: AVAILABLE\n");
    #else
    printf("   GCC extensions: NOT AVAILABLE\n");
    #endif
    printf("\n");
    
    // 6. C Standard
    printf("6. C Standard:\n");
    #if defined(__STDC_VERSION__)
        #if __STDC_VERSION__ >= 201112L
            printf("   Standard: C11 or later\n");
        #elif __STDC_VERSION__ >= 199901L
            printf("   Standard: C99\n");
        #else
            printf("   Standard: C90\n");
        #endif
    #else
        printf("   Standard: Pre-C90\n");
    #endif
    printf("\n");
    
    // 7. Computation with timing and validation
    printf("7. Computation (with features):\n");
    int result = compute(100);
    printf("   Result: %d\n\n", result);
    
    // 8. Fast multiply with optimization hints
    printf("8. Optimized Functions:\n");
    printf("   5 * 10 = %d\n", fast_multiply(5, 10));
    printf("   0 * 10 = %d (optimized path)\n", fast_multiply(0, 10));
    printf("\n");
    
    // 9. Build configuration
    printf("9. Build Configuration:\n");
    #ifdef NDEBUG
    printf("   Build type: RELEASE\n");
    #else
    printf("   Build type: DEBUG\n");
    #endif
    
    #ifdef __OPTIMIZE__
    printf("   Optimizations: ENABLED\n");
    #else
    printf("   Optimizations: DISABLED\n");
    #endif
    printf("\n");
    
    // 10. Compile-time information
    printf("10. Compile-Time Information:\n");
    printf("    Compiled on: %s at %s\n", __DATE__, __TIME__);
    #ifdef __FILE__
    printf("    Source file: %s\n", __FILE__);
    #endif
    
    return 0;
}
