/*
Question 5: Selection Sort

Description:
Implement selection sort for an integer array.

Selection sort repeatedly finds the smallest element from the unsorted
portion of the array and swaps it with the first element of the unsorted
portion.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
- Do not use any built-in sorting function.
*/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Implementation of the Selection Sort algorithm.
 */
void selectionSort(int arr[], int size) {
    // If the array is empty or has only one element, do nothing
    if (arr == 0 || size < 2) {
        return;
    }

    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in the unsorted array
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        // only if a smaller element was actually found
        if (minIndex != i) {
            swap(&arr[minIndex], &arr[i]);
        }
    }
}