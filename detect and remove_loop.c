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

struct Node* detectLoop(struct Node* head) {
    struct Node* slow = head; 
    struct Node* fast = head; 

    while (slow && fast && fast->next) {
        slow = slow->next;         
        fast = fast->next->next;   

        if (slow == fast) {        
            printf("Loop detected.\n");
            return slow;
        }
    }
    return NULL; 
}


void removeLoop(struct Node* head, struct Node* loopNode) {
    struct Node* ptr1 = head;      
    struct Node* ptr2;

    while (1) {
        ptr2 = loopNode;
       while (ptr2->next != loopNode && ptr2->next != ptr1) {
            ptr2 = ptr2->next;
        }
        if (ptr2->next == ptr1) {
            break;
        }
        ptr1 = ptr1->next;
    }

    ptr2->next = NULL;
    printf("Loop removed.\n");
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

    // Create a linked list
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // Introduce a loop for testing
    head->next->next->next->next->next = head->next;

    // Detect and remove the loop
    struct Node* loopNode = detectLoop(head);
    if (loopNode != NULL) {
        removeLoop(head, loopNode);
    } else {
        printf("No loop found.\n");
    }

    // Display the modified linked list
    displayList(head);

    return 0;
}

