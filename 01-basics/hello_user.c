/*
 * hello_user.c
 * A program that greets the user by name
 */

#include <stdio.h>

int main() {
    char name[50];
    
    // Prompt user for their name
    printf("What is your name? ");
    
    // Read user input
    scanf("%s", name);
    
    // Greet the user
    printf("Hello, %s! Welcome to C programming.\n", name);
    
    return 0;
}
