#include <stdio.h>
#include <stdlib.h>

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

void swapNodes(struct Node** head, int x, int y) {
    if (x == y) return; 
    struct Node *prev1 = NULL, *prev2 = NULL;
    struct Node *node1 = *head, *node2 = *head;

    while (node1 && node1->data != x) {
        prev1 = node1;
        node1 = node1->next;
    }

    while (node2 && node2->data != y) {
        prev2 = node2;
        node2 = node2->next;
    }

    if (!node1 || !node2) return;

    if (prev1) {
        prev1->next = node2;
    } else {
        *head = node2;
    }

    if (prev2) {
        prev2->next = node1;
    } else { 
        *head = node1;
    }

    struct Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    swapNodes(&head, 2, 4);

    printf("List after swapping 2 and 4: ");
    printList(head);

    return 0;
}
