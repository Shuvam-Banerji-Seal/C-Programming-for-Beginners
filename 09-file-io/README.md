# Module 09: File I/O 📁

Master file operations in C!

## 📚 What You'll Learn

1. File handling basics
2. Reading and writing text files
3. Binary file operations
4. File positioning
5. Error handling

## 📝 Text File Operations

```c
#include <stdio.h>

int main() {
    // Writing
    FILE *fp = fopen("output.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "Hello, File!\n");
        fclose(fp);
    }
    
    // Reading
    fp = fopen("output.txt", "r");
    if (fp != NULL) {
        char buffer[100];
        while (fgets(buffer, 100, fp) != NULL) {
            printf("%s", buffer);
        }
        fclose(fp);
    }
    
    return 0;
}
```

## 💾 Binary Files

```c
struct Data {
    int id;
    float value;
};

// Write binary
FILE *fp = fopen("data.bin", "wb");
struct Data d = {1, 3.14};
fwrite(&d, sizeof(struct Data), 1, fp);
fclose(fp);

// Read binary
fp = fopen("data.bin", "rb");
fread(&d, sizeof(struct Data), 1, fp);
fclose(fp);
```

## 🔜 Next Module

[Module 10: Preprocessor and Macros](../10-preprocessor/README.md)
