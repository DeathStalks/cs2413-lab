// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    // If the list is empty or has only one node, nothing to swap
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Use a dummy node to act as the "previous" node for the first pair
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // Traverse the list as long as there is a pair of nodes left to swap
    while (prev->next != NULL && prev->next->next != NULL) {
        // Identify the two nodes to be swapped
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;

        // Rewire the pointers
        first->next = second->next; // 1 points to 3 (or NULL)
        second->next = first;       // 2 points to 1
        prev->next = second;        // prev (or dummy) points to 2

        // Advance the 'prev' pointer for the next iteration
        prev = first; 
    }

    // The new head of the list is whatever the dummy node points to
    return dummy.next;
}