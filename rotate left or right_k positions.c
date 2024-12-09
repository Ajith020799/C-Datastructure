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

int getLength(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* rotateLeft(struct Node* head, int k) {
    if (!head || k == 0) return head;

    int length = getLength(head);
    k = k % length; 
    if (k == 0) return head;

    struct Node* current = head;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }

    struct Node* newHead = current->next;
    current->next = NULL;

    struct Node* temp = newHead;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || k == 0) return head;

    int length = getLength(head);
    k = k % length; 
    if (k == 0) return head;

    int splitPoint = length - k;
    struct Node* current = head;
    for (int i = 1; i < splitPoint; i++) {
        current = current->next;
    }

    struct Node* newHead = current->next;
    current->next = NULL;

    struct Node* temp = newHead;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
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

    int k = 2;

    head = rotateLeft(head, k);
    printf("List after left rotation by %d: ", k);
    printList(head);

    head = rotateRight(head, k);
    printf("List after right rotation by %d: ", k);
    printList(head);

    return 0;
}

