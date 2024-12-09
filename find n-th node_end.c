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
void findNthFromEnd(struct Node* head, int n) {
    struct Node* first = head; 
    struct Node* second = head; 
    int count = 0;

    while (count < n) {
        if (first == NULL) { 
            printf("The list has fewer than %d nodes.\n", n);
            return;
        }
        first = first->next;
        count++;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    printf("The %dth node from the end is: %d\n", n, second->data);
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
    head->next->next->next->next = createNode(50);
    displayList(head);
    int n = 2; // Example: Find the 2nd node from the end
    findNthFromEnd(head, n);

    return 0;
}
