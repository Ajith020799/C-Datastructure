
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseK(struct ListNode* head, int k) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev_group_end = &dummy;

    while (1) {
        struct ListNode* group_start = prev_group_end->next;
        struct ListNode* group_end = prev_group_end;

        for (int i = 0; i < k && group_end != NULL; i++) {
            group_end = group_end->next;
        }

        if (group_end == NULL) break; 

        struct ListNode* next_group_start = group_end->next;

        group_end->next = NULL; 
        prev_group_end->next = reverseK(group_start, k);

        group_start->next = next_group_start;

        prev_group_end = group_start;
    }

    return dummy.next;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    printf("Reversed in groups of %d:\n", k);
    printList(head);

    return 0;
}

