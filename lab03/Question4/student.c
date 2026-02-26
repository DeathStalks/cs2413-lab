// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // Handle the edge case of an empty list
    if (head == NULL) {
        return -1;
    }

    // Initialize both pointers at the head of the list
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Fast pointer moves 2 steps, slow pointer moves 1 step.
    // Loop stops when fast reaches the end (NULL) or the last node.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // When fast reaches the end, slow is at the middle.
    // For even-length lists, this naturally lands on the second middle node.
    return slow->val;
}