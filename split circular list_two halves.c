#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; 
    return newNode;
}
void splitCircularList(struct Node* head, struct Node** head1, struct Node** head2) {
    if (head == NULL || head->next == head) {
        *head1 = head;
        *head2 = NULL;
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head) {
        fast = fast->next;
    }

    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;
    fast->next = *head2;
}
void printCircularList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    // Create a circular linked list: 1 -> 2 -> 3 -> 4 -> 5 -> (back to 1)
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = head; 
    printf("Original Circular List: ");
    printCircularList(head);

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    splitCircularList(head, &head1, &head2);

    printf("First Half: ");
    printCircularList(head1);

    printf("Second Half: ");
    printCircularList(head2);

    return 0;
}

