/*
 * hash_table.c
 * Hash table implementation with chaining
 * Topics: Hash functions, collision resolution, load factor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _POSIX_C_SOURCE 200809L

#define TABLE_SIZE 10

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry **buckets;
    int size;
    int count;
} HashTable;

// Hash function (djb2)
unsigned int hash(const char *str, int table_size) {
    unsigned long hash_val = 5381;
    int c;
    
    while ((c = *str++)) {
        hash_val = ((hash_val << 5) + hash_val) + c; // hash * 33 + c
    }
    
    return hash_val % table_size;
}

// Create hash table
HashTable* createHashTable(int size) {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->buckets = (Entry**)calloc(size, sizeof(Entry*));
    return table;
}

// Create entry
Entry* createEntry(const char *key, int value) {
    Entry *entry = (Entry*)malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// Insert or update
void insert(HashTable *table, const char *key, int value) {
    unsigned int index = hash(key, table->size);
    Entry *entry = table->buckets[index];
    
    // Check if key exists
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;  // Update
            return;
        }
        entry = entry->next;
    }
    
    // Insert new entry at head
    Entry *new_entry = createEntry(key, value);
    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
    table->count++;
}

// Search
int search(HashTable *table, const char *key, int *value) {
    unsigned int index = hash(key, table->size);
    Entry *entry = table->buckets[index];
    
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            *value = entry->value;
            return 1;  // Found
        }
        entry = entry->next;
    }
    
    return 0;  // Not found
}

// Delete
int delete(HashTable *table, const char *key) {
    unsigned int index = hash(key, table->size);
    Entry *entry = table->buckets[index];
    Entry *prev = NULL;
    
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (prev == NULL) {
                table->buckets[index] = entry->next;
            } else {
                prev->next = entry->next;
            }
            free(entry->key);
            free(entry);
            table->count--;
            return 1;
        }
        prev = entry;
        entry = entry->next;
    }
    
    return 0;
}

// Display hash table
void display(HashTable *table) {
    printf("   Hash Table (size=%d, count=%d, load=%.2f):\n", 
           table->size, table->count, 
           (float)table->count / table->size);
    
    for (int i = 0; i < table->size; i++) {
        printf("   [%d]: ", i);
        Entry *entry = table->buckets[i];
        
        if (entry == NULL) {
            printf("empty\n");
        } else {
            while (entry != NULL) {
                printf("(%s: %d) -> ", entry->key, entry->value);
                entry = entry->next;
            }
            printf("NULL\n");
        }
    }
}

// Get load factor
float loadFactor(HashTable *table) {
    return (float)table->count / table->size;
}

// Count collisions
int countCollisions(HashTable *table) {
    int collisions = 0;
    for (int i = 0; i < table->size; i++) {
        Entry *entry = table->buckets[i];
        int chain_length = 0;
        
        while (entry != NULL) {
            chain_length++;
            entry = entry->next;
        }
        
        if (chain_length > 1) {
            collisions += (chain_length - 1);
        }
    }
    return collisions;
}

// Free hash table
void freeHashTable(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Entry *entry = table->buckets[i];
        while (entry != NULL) {
            Entry *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

int main() {
    printf("=== Hash Table with Chaining ===\n\n");
    
    HashTable *table = createHashTable(TABLE_SIZE);
    
    // Insert operations
    printf("1. Insert Operations:\n");
    insert(table, "apple", 100);
    insert(table, "banana", 200);
    insert(table, "cherry", 300);
    insert(table, "date", 400);
    insert(table, "elderberry", 500);
    printf("   Inserted 5 items\n\n");
    
    display(table);
    printf("\n");
    
    // Search operations
    printf("2. Search Operations:\n");
    int value;
    if (search(table, "banana", &value)) {
        printf("   Found 'banana': %d\n", value);
    }
    if (!search(table, "grape", &value)) {
        printf("   'grape' not found\n\n");
    }
    
    // Update operation
    printf("3. Update Operation:\n");
    insert(table, "apple", 150);  // Update existing key
    if (search(table, "apple", &value)) {
        printf("   Updated 'apple': %d\n\n", value);
    }
    
    // Statistics
    printf("4. Statistics:\n");
    printf("   Count: %d\n", table->count);
    printf("   Load factor: %.2f\n", loadFactor(table));
    printf("   Collisions: %d\n\n", countCollisions(table));
    
    // More insertions to demonstrate collisions
    printf("5. Demonstrating Collisions:\n");
    insert(table, "fig", 600);
    insert(table, "grape", 700);
    insert(table, "honeydew", 800);
    printf("   Added more items:\n");
    display(table);
    printf("   Collisions: %d\n\n", countCollisions(table));
    
    // Delete operation
    printf("6. Delete Operation:\n");
    if (delete(table, "banana")) {
        printf("   Deleted 'banana'\n");
    }
    display(table);
    printf("\n");
    
    // Final statistics
    printf("7. Final Statistics:\n");
    printf("   Count: %d\n", table->count);
    printf("   Load factor: %.2f\n", loadFactor(table));
    
    // Cleanup
    freeHashTable(table);
    printf("\n   Memory freed\n");
    
    return 0;
}
