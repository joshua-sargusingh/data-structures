#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table {
    int size;
    struct node** buckets;
};

struct node {
    char *name;
    char *num;
    struct node* next;
};

struct table* table_create(int size) {
    struct table* phonebook = (struct table*)malloc(sizeof(struct table));

    if (phonebook == NULL) {
        printf("memory allocation error");
        exit(1);
    }

    phonebook->size = size;

    //calloc is a function in C that allocates a block of memory for an array of elements and initializes all the memory to zero.
    phonebook->buckets = (struct node**)calloc(size, sizeof(struct node*));

    if (phonebook->buckets == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    return phonebook;
}

struct node* node_create(char *name, char *num) {
    struct node* node_new = (struct node*)malloc(sizeof(struct node));

    if (node_new == NULL) {
        printf("memory allocation error");
        exit(1);
    }

    node_new -> name = strdup(name);
    node_new -> num = strdup(num);
    node_new -> next = NULL;

    return node_new;
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

void node_insert(struct table* phonebook, char *name, char *num) {
    int index = hash(name, phonebook->size);

    struct node* node = node_create(name, num);

    node->next = phonebook->buckets[index];
    phonebook->buckets[index] = node;
}

void table_search(struct table* phonebook, char *name, char *num_exist) {
    //used to determine index where key should be located:
    int index = hash(name, phonebook->size);
    struct node *current = phonebook->buckets[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(num_exist, current->num);
        }
        current = current->next;
    }
}

void table_print(struct table* phonebook) {

    printf("Print Phonebook:\n");

    for (int i = 0; i<phonebook->size; ++i) {

        printf("[%d]: ", i);

        struct node *current = phonebook->buckets[i];

        while (current != NULL) {
            printf("(%s %s) ", current->name, current->num);
            current = current->next;
        }

    }

    printf("\n");
}

void table_free(struct table* phonebook) {

    for (int i = 0; i<phonebook->size; ++i) {

        struct node *current = phonebook->buckets[i];
        struct node *temp = current;

        while (current != NULL) {
            struct node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(phonebook->buckets);
    free(phonebook);
}


int main() {

    //init
    struct table* phonebook = table_create(8);

    node_insert(phonebook, "James", "808-808-8080");
    node_insert(phonebook, "Jimbo", "222-222-2222");
    node_insert(phonebook, "Lief", "000-000-9090");

    char num_exist[12];
    table_search(phonebook, "Jordan", num_exist);
    printf("Number for name 'Jordan': %s\n", num_exist);

    table_search(phonebook, "Jimbo", num_exist);
    printf("Number for name 'Jimbo': %s\n", num_exist);

    table_print(phonebook);

    table_free(phonebook);

    return 0;
}