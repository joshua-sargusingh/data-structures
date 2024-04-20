#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hashTable {
    int size;
    struct Node** buckets;
};

struct Node {
    char *key;
    int value;
    struct Node* next;
};

struct Node* createNode(char *key, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("memory allocation error");
        exit(1);
    }

    node -> key = strdup(key);
    node -> value = value;
    node -> next = NULL;

    return node;
}

struct hashTable* initHashTable(int size) {
    struct hashTable* hashTable = (struct hashTable*)malloc(sizeof(struct hashTable));

    if (hashTable == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    
    hashTable -> size = size;

    //calloc is a function in C that allocates a block of memory for an array of elements and initializes all the memory to zero.
    hashTable->buckets = (struct Node **)calloc(size, sizeof(struct Node *));
    
    if (hashTable->buckets == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    
    return hashTable;
}

int hash(char *key, int size) {
    unsigned int hashValue = 0;

    // Using a simple hash function with prime number 31
    const int c = 31;

    //iterate through word to create hash
    while (*key != '\0') {
        //replace old hash value with new one from ASCII key
        hashValue = (hashValue * c) + *key;
        key++;
    }

    return hashValue % size; // Ensure index is within bounds of hash table size
}

// Insert a key-value pair into the hash table
void insert(struct hashTable* hashTable, char *key, int value) {
    int index = hash(key, hashTable->size);
    struct Node *node = createNode(key, value);

    // Insert at the head of the linked list (separate chaining for collision resolution)
    // point to current head
    node->next = hashTable->buckets[index];
    //reset head to be current node
    hashTable->buckets[index] = node;

    //To access
    //hashTable->buckets[index]->node(key/value)
}

// Search for a key in the hash table and return its corresponding value
int search(struct hashTable *hashTable, char *key) {
    //used to determine index where key should be located:
    int index = hash(key, hashTable->size);
    struct Node *current = hashTable->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; // Key found, return its value
        }
        current = current->next;
    }

    return -1; // Key not found
}

// Print the contents of the hash table
void printHashTable(struct hashTable *hashTable) {
    printf("Hash Table Contents:\n");

    for (int i = 0; i < hashTable->size; i++) {
        //declare current as temp
        struct Node *current = hashTable->buckets[i];

        //always print every i
        printf("[%d]: ", i);

        //check to print all data in bucket
        while (current != NULL) {
            printf("(%s, %d) ", current->key, current->value);
            current = current->next;
        }

        //new line
        printf("\n");
    }
}

// Free a single HashNode and its key string
void freeNode(struct Node *node) {
    if (node != NULL) {
        free(node->key); // Free the duplicated key string
        free(node);      // Free the HashNode itself
    }
}

void freeTable(struct hashTable *hashTable) {
    //iterate through hash table
    if (hashTable != NULL) {
        //iterate through buckets
        for (int i = 0; i < hashTable->size; ++i) {
            struct Node *current = hashTable->buckets[i];

            //require holder to iterate through ll
            while (current != NULL) {
                struct Node *temp = current;
                current = current->next;
                freeNode(temp); // Free each node in the bucket
            }
        }

        free(hashTable->buckets); // Free the buckets array
        free(hashTable);          // Free the hash table structure
    }
}

int main() {
    //INIT
    struct hashTable *hashTable = initHashTable(10);

    //INSERT key-value pairs into hash table
    insert(hashTable, "apple", 10);
    insert(hashTable, "banana", 20);
    insert(hashTable, "cherry", 30);
    insert(hashTable, "date", 40);

    //SEARCH
    printf("Value for key 'banana': %d\n", search(hashTable, "banana"));
    printf("Value for key 'grape': %d\n", search(hashTable, "grape"));

    //PRINT
    printHashTable(hashTable);

    //FREE
    freeTable(hashTable);

    return 0;
}