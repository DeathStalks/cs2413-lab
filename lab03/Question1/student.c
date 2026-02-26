// Question1/student.c
// ------------------------------------------------------------
// CS Lab03 - Reverse Linked List 
//
// TODO:
//   Implement reverseList(head) to reverse a singly linked list.
//
// Rules:
// - Do not allocate new nodes.
// - Do not use recursion.
// - Return the new head pointer.
// ------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* nextTemp = NULL;

    while (curr != NULL) {
        // 1. Save the next node so we don't lose the rest of the list
        nextTemp = curr->next;
        
        // 2. Reverse the link: point current node backward to previous
        curr->next = prev;
        
        // 3. Move the 'prev' and 'curr' pointers one step forward
        prev = curr;
        curr = nextTemp;
    }

    // When curr becomes NULL, prev is pointing to the new head
    return prev;
}