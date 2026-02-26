// Question3/student.c
// ------------------------------------------------------------
// CS Lab03 - Linked List Cycle 
//
// TODO:
//   Implement hasCycle(head) using fast/slow pointers.
//
// Rules:
// - Do not allocate new nodes.
// - Do not modify the list.
// ------------------------------------------------------------

#include "student.h"

bool hasCycle(struct ListNode *head) {
    // An empty list or a list with only one node (and no self-loop) cannot have a cycle.
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // Initialize both pointers to the start of the list
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Traverse the list
    // We check fast->next != NULL because fast jumps two nodes at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Tortoise moves 1 step
        fast = fast->next->next;    // Hare moves 2 steps

        // If the fast pointer laps the slow pointer, a cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // If the fast pointer reaches the end of the list (NULL), there is no cycle
    return false;
}