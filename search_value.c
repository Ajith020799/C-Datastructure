
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int searchValue(struct Node* head, int value) {
    struct Node* temp = head; 
    int position = 1;       
    while (temp != NULL) {   
        if (temp->data == value) { 
            return position;       
        temp = temp->next;         
        position++;                
    }
    return -1;                     
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    displayList(head);

    int valueToSearch = 30;
    int result = searchValue(head, valueToSearch);
    if (result != -1) {
        printf("Value %d found at position %d.\n", valueToSearch, result);
    } else {
        printf("Value %d not found in the linked list.\n", valueToSearch);
    }

    return 0;
}
