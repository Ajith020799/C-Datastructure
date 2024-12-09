#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
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
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;    
    free(temp);               
}
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) { 
        temp = temp->next;
    }
    free(temp->next);       
    temp->next = NULL;      
}

void deleteAtMiddle(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (position == 1) { 
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next; 
    }
    if (temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next; 
    temp->next = nodeToDelete->next;        
    free(nodeToDelete);                    
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

    printf("Deleting node from the beginning...\n");
    deleteAtBeginning(&head);
    displayList(head);

    printf("Deleting node from the end...\n");
    deleteAtEnd(&head);
    displayList(head);

    printf("Deleting node from position 2...\n");
    deleteAtMiddle(&head, 2);
    displayList(head);

    return 0;
}

