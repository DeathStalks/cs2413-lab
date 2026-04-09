/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    // Allocate memory for a min-heap of size k
    int* heap = (int*)malloc(k * sizeof(int));
    if (!heap) {
        return -1; // Allocation failed
    }

    // Initialize the heap with the first k elements of the array
    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
    }

    // Build the min-heap (O(k) time complexity)
    for (int i = k / 2 - 1; i >= 0; i--) {
        heapifyDown(heap, k, i);
    }

    // Process the remaining elements
    for (int i = k; i < numsSize; i++) {
        // If the current element is larger than the smallest in our heap,
        // it belongs in the top k elements. Replace the root and heapify down.
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }

    // The root of the min-heap is the kth largest element
    int kthLargest = heap[0];
    free(heap);
    
    return kthLargest;
}

/*
Optional helper: swap two integers.
*/
static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
static void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        // If current node is smaller than its parent, swap them
        if (heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* heap, int size, int index) {
    int smallest = index;
    
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Check if left child exists and is smaller than the current smallest
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // Check if right child exists and is smaller than the current smallest
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // If the smallest is not the current index, swap and continue down
        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            // The heap property is satisfied
            break;
        }
    }
}