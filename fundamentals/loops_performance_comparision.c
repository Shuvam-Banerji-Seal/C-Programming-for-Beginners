#include <stdio.h>
#include <time.h>

#define N 1000000000UL  // 1 billion iterations

int main(void) {
    clock_t start, end;
    double cpu_time_used;
    volatile unsigned long sum;  // volatile prevents compiler optimization

    // --- For loop ---
    sum = 0;
    start = clock();
    for (unsigned long i = 0; i < N; i++) {
        sum += i;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("For loop:     %.3f seconds (sum=%lu)\n", cpu_time_used, sum);

    // --- While loop ---
    sum = 0;
    unsigned long j = 0;
    start = clock();
    while (j < N) {
        sum += j;
        j++;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("While loop:   %.3f seconds (sum=%lu)\n", cpu_time_used, sum);

    // --- Do-while loop ---
    sum = 0;
    unsigned long k = 0;
    start = clock();
    if (N > 0) {
        do {
            sum += k;
            k++;
        } while (k < N);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Do-while loop: %.3f seconds (sum=%lu)\n", cpu_time_used, sum);

    return 0;
}
