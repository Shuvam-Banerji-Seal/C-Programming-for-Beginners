#include <stdio.h>
// functions declaration
void function1();
void function2(int a);
char function3();
int function4(int a, int b);
float function5(float a, float b);
int function6(float a, float b);

///////////////////////////////////////
void function1() {

    /*
    This is a multi-line comment
    */
    printf("This is function 1\n");
}

void function2(int a) {
    printf("This is function 2 with argument %d\n", a);
}

char function3() {
    printf("This is function 3 returning a char\n");
    return 'A';
}

int function4(int a, int b) {
    printf("This is function 4 with arguments %d and %d\n", a, b);
    return a + b;
}

float function5(float a, float b) {
    printf("This is function 5 with arguments %.2f and %.2f\n", a, b);
    return a * b;

}
// what would happen if the function type and the function return type do not match?
// If the function type and the return type do not match, it can lead to undefined behavior.
// For example, if a function is declared to return an int but returns a float,
// the caller may not receive the expected value, leading to potential errors.


int function6(float a, float b) {
    printf("This is function 6 with arguments %d and %df\n", a, b);
    return (float)(a * b);
}


int main() {
    function1();
    function2(42);
    function3();
    function4(5, 10);
    function5(2.5, 4.0);
    function6(2.5, 4.0);
    return 0;
}