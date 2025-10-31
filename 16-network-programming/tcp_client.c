#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE];
    
    printf("=== Simple TCP Client ===\n");
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert address
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("Invalid address\n");
        return -1;
    }
    
    // Connect
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }
    
    printf("Connected to server!\n");
    
    // Receive greeting
    read(sock, buffer, BUFFER_SIZE);
    printf("Server: %s\n\n", buffer);
    
    // Communication loop
    printf("Type messages (type 'quit' to exit):\n");
    while (1) {
        printf("You: ");
        if (fgets(message, BUFFER_SIZE, stdin) == NULL) {
            break;
        }
        
        if (strncmp(message, "quit", 4) == 0) {
            break;
        }
        
        // Send message
        send(sock, message, strlen(message), 0);
        
        // Receive echo
        memset(buffer, 0, BUFFER_SIZE);
        read(sock, buffer, BUFFER_SIZE);
        printf("Server: %s", buffer);
    }
    
    printf("Closing connection...\n");
    close(sock);
    
    return 0;
}
