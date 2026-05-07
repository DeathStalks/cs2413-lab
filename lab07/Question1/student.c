#include <stdbool.h>

/*
Question 1: Bubble Sort

Description:
Implement two versions of bubble sort for an integer array.

1. bubbleSort:
   Implement the basic bubble sort algorithm.
   Repeatedly compare adjacent elements and swap them if they are
   in the wrong order. After each pass, the largest unsorted element
   should move to its correct position.

2. bubbleSortOptimized:
   Implement an improved version of bubble sort.
   This version should stop early if a full pass completes without
   any swaps, which means the array is already sorted.

Both functions should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    // If the array is empty or has only one element, do nothing
    if (size <= 1) {
        return;
    }

    // Outer loop for the number of passes
    for (int i = 0; i < size - 1; i++) {
        // Inner loop performs the comparisons and swaps.
        // The last 'i' elements are already in place, so we don't need to check them.
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSortOptimized(int arr[], int size) {
    // If the array is empty or has only one element, do nothing
    if (size <= 1) {
        return;
    }

    bool swapped;
    
    // Outer loop for the number of passes
    for (int i = 0; i < size - 1; i++) {
        swapped = false; // Reset the flag at the start of each pass
        
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }
        
        // If no elements were swapped during the pass, the array is fully sorted
        if (!swapped) {
            break;
        }
    }
}