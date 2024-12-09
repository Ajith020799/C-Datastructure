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
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1; 
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; 
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);
    head1->next->next->next->next = createNode(5);

    struct Node* head2 = createNode(10);
    head2->next = createNode(11);
    head2->next->next = head1->next->next; 

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    struct Node* intersection = getIntersectionNode(head1, head2);
    if (intersection) {
        printf("Intersection point is at node with value: %d\n", intersection->data);
    } else {
        printf("No intersection point.\n");
    }

    return 0;
}

