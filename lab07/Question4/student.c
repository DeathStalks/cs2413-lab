/*
Question 4: Insertion Sort

Description:
Implement insertion sort for an integer array.

Insertion sort builds the sorted portion of the array one element at a time.
For each element, it inserts that element into the correct position among
the elements before it.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- Do not use any built-in sorting function.
*/

void insertionSort(int arr[], int size) {
    // Check for base cases: null pointer or array size 0/1
    if (arr == 0 || size < 2) {
        return;
    }

    for (int i = 1; i < size; i++) {
        int key = arr[i];   // The element currently being positioned
        int j = i - 1;      // The index of the element immediately to the left

        /* * Move elements of arr[0..i-1] that are greater than the key 
         * one position to the right to make space for the key.
         */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // Insert the key into its correct sorted position
        arr[j + 1] = key;
    }
}