/*
 * bitfields_and_unions.c
 * Advanced bit fields and unions
 * Topics: Bit manipulation with structures, union memory sharing, packed structures
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Bit fields for network packet header
typedef struct {
    unsigned int version : 4;      // IP version (4 bits)
    unsigned int header_len : 4;   // Header length (4 bits)
    unsigned int tos : 8;          // Type of service (8 bits)
    unsigned int total_len : 16;   // Total length (16 bits)
    unsigned int id : 16;          // Identification (16 bits)
    unsigned int flags : 3;        // Flags (3 bits)
    unsigned int frag_offset : 13; // Fragment offset (13 bits)
    unsigned int ttl : 8;          // Time to live (8 bits)
    unsigned int protocol : 8;     // Protocol (8 bits)
} IPHeader;

// Bit fields for file permissions (like Unix)
typedef struct {
    unsigned int read : 1;
    unsigned int write : 1;
    unsigned int execute : 1;
} Permissions;

typedef struct {
    char filename[50];
    Permissions owner;
    Permissions group;
    Permissions others;
} FileInfo;

// Union for type conversion
typedef union {
    int i;
    float f;
    char bytes[4];
} DataConverter;

// Union for efficient memory usage
typedef union {
    struct {
        char type;
        union {
            int int_val;
            float float_val;
            char str_val[20];
        } value;
    } data;
    char raw[24];
} FlexibleData;

// Packed structure using pragma
#pragma pack(push, 1)
typedef struct {
    uint8_t type;
    uint16_t length;
    uint32_t timestamp;
    uint8_t data[10];
} PackedMessage;
#pragma pack(pop)

// Union for IPv4 address representation
typedef union {
    uint32_t addr_int;
    struct {
        uint8_t octet1;
        uint8_t octet2;
        uint8_t octet3;
        uint8_t octet4;
    } octets;
    uint8_t bytes[4];
} IPv4Address;

// Print permissions
void printPermissions(Permissions p) {
    printf("%c%c%c", 
           p.read ? 'r' : '-',
           p.write ? 'w' : '-',
           p.execute ? 'x' : '-');
}

int main() {
    printf("=== Bit Fields and Unions ===\n\n");
    
    // 1. IP Header bit fields
    printf("1. Network Packet Header (Bit Fields):\n");
    IPHeader header = {
        .version = 4,
        .header_len = 5,
        .tos = 0,
        .total_len = 60,
        .id = 12345,
        .flags = 2,
        .frag_offset = 0,
        .ttl = 64,
        .protocol = 6  // TCP
    };
    
    printf("   IP Version: %u\n", header.version);
    printf("   Header Length: %u words\n", header.header_len);
    printf("   Total Length: %u bytes\n", header.total_len);
    printf("   TTL: %u\n", header.ttl);
    printf("   Protocol: %u (TCP)\n", header.protocol);
    printf("   Size of IPHeader: %zu bytes\n\n", sizeof(IPHeader));
    
    // 2. File permissions using bit fields
    printf("2. File Permissions (Unix-like):\n");
    FileInfo file = {
        .filename = "example.txt",
        .owner = {1, 1, 0},    // rw-
        .group = {1, 0, 0},    // r--
        .others = {1, 0, 0}    // r--
    };
    
    printf("   File: %s\n", file.filename);
    printf("   Permissions: ");
    printPermissions(file.owner);
    printPermissions(file.group);
    printPermissions(file.others);
    printf(" (rw-r--r--)\n\n");
    
    // 3. Data type converter union
    printf("3. Data Type Converter Union:\n");
    DataConverter conv;
    
    conv.i = 1065353216;  // IEEE 754 representation of 1.0f
    printf("   As integer: %d\n", conv.i);
    printf("   As float: %.1f\n", conv.f);
    printf("   As bytes: 0x");
    for (int i = 0; i < 4; i++) {
        printf("%02X", (unsigned char)conv.bytes[i]);
    }
    printf("\n\n");
    
    // 4. Endianness detection using union
    printf("4. Endianness Detection:\n");
    union {
        uint32_t value;
        uint8_t bytes[4];
    } endian_test;
    
    endian_test.value = 0x01020304;
    if (endian_test.bytes[0] == 0x01) {
        printf("   System is Big Endian\n");
    } else {
        printf("   System is Little Endian\n");
    }
    printf("   Value 0x01020304 stored as: ");
    for (int i = 0; i < 4; i++) {
        printf("0x%02X ", endian_test.bytes[i]);
    }
    printf("\n\n");
    
    // 5. IPv4 address union
    printf("5. IPv4 Address Representation:\n");
    IPv4Address ip;
    ip.octets.octet1 = 192;
    ip.octets.octet2 = 168;
    ip.octets.octet3 = 1;
    ip.octets.octet4 = 100;
    
    printf("   IP Address: %u.%u.%u.%u\n", 
           ip.octets.octet1, ip.octets.octet2, 
           ip.octets.octet3, ip.octets.octet4);
    printf("   As integer: 0x%08X\n", ip.addr_int);
    printf("   As bytes: ");
    for (int i = 0; i < 4; i++) {
        printf("0x%02X ", ip.bytes[i]);
    }
    printf("\n\n");
    
    // 6. Flexible data structure with union
    printf("6. Flexible Data Structure:\n");
    FlexibleData fd1, fd2, fd3;
    
    fd1.data.type = 'I';
    fd1.data.value.int_val = 42;
    printf("   Type: %c, Value: %d\n", fd1.data.type, fd1.data.value.int_val);
    
    fd2.data.type = 'F';
    fd2.data.value.float_val = 3.14f;
    printf("   Type: %c, Value: %.2f\n", fd2.data.type, fd2.data.value.float_val);
    
    fd3.data.type = 'S';
    strcpy(fd3.data.value.str_val, "Hello");
    printf("   Type: %c, Value: %s\n\n", fd3.data.type, fd3.data.value.str_val);
    
    // 7. Packed structures
    printf("7. Packed Structure (no padding):\n");
    PackedMessage msg = {
        .type = 1,
        .length = 10,
        .timestamp = 1234567890,
        .data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    };
    
    printf("   Size of PackedMessage: %zu bytes\n", sizeof(PackedMessage));
    printf("   Type: %u\n", msg.type);
    printf("   Length: %u\n", msg.length);
    printf("   Timestamp: %u\n", msg.timestamp);
    printf("   (Packed structure has no padding between fields)\n\n");
    
    // 8. Memory efficiency comparison
    printf("8. Memory Efficiency:\n");
    struct Regular {
        char c;
        int i;
        char d;
    };
    
    struct __attribute__((packed)) Packed {
        char c;
        int i;
        char d;
    };
    
    printf("   Regular struct size: %zu bytes (with padding)\n", sizeof(struct Regular));
    printf("   Packed struct size: %zu bytes (no padding)\n", sizeof(struct Packed));
    printf("   Memory saved: %zu bytes\n", 
           sizeof(struct Regular) - sizeof(struct Packed));
    
    return 0;
}
