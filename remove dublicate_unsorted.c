#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int hash(int value) {
    return abs(value) % TABLE_SIZE;
}
bool isPresent(bool* hashTable, int value) {
    int index = hash(value);
    return hashTable[index];
}
void addToHashTable(bool* hashTable, int value) {
    int index = hash(value);
    hashTable[index] = true;
}
void removeDuplicates(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return; 
    }

    bool hashTable[TABLE_SIZE] = {false}; // Initialize hash table
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (isPresent(hashTable, current->data)) {
            // Duplicate found, remove the current node
            prev->next = current->next;
            free(current);
        } else {
            addToHashTable(hashTable, current->data);
            prev = current;
        }
        current = prev->next;
    }
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(10);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(20);

    printf("Original List: ");
    printList(head);

    removeDuplicates(head);

    printf("List After Removing Duplicates: ");
    printList(head);

    return 0;
}
