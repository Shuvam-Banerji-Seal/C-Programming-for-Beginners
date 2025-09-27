#include <stdio.h>


// * --> Value at address

// & --> Address of variable

// *(arr+i) == arr[i]

void array_general()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printf("\n The address of the array is %p and the value  is %d, and just the array variable is %p\n", (void*)arr, *(arr+1), arr);
    // printf("When we try to print *(arr[1]) we get %d\n", (void*)(arr[1]));
    // printf("When we try to print *(arr[1]) we get %d\n", *(arr+1));
    for (int i = 0; i < 5; i++) {
        printf("The value at index %d is %d and address is %p\n", i, arr[i], (void*)&arr[i]);
    }
}


int main() {
    char str1[] = "Hello,"; char str2[] = "World!"; char str3[20];

    // Buffer Overread Example
    // for (int i = 0; i < 19; i++) {
    //     printf("The address of str1[%d] is %p and value is %c\n", i, (void*)&str1[i], str1[i]);
    // }
    int count = 0;
    while (str1[count] != '\0') {
        count++;
    }
    printf("Length of str1 is %d\n", count);

    // Concatenate str1 and str2 into str3
    snprintf(str3, sizeof(str3), "%s%s", str1, str2);

    // Print the concatenated string
    printf("%s\n", str3);
    // array_general();
    return 0;
}