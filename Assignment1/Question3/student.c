#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Allocate memory for the standard case (no overflow at the most significant digit)
    int* result = (int*)malloc(digitsSize * sizeof(int));
    
    // Copy the original digits into our new result array
    for (int i = 0; i < digitsSize; i++) {
        result[i] = digits[i];
    }

    // Traverse the array from right to left (least to most significant digit)
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (result[i] < 9) {
            // No carry-over needed; just increment and return
            result[i]++;
            *returnSize = digitsSize;
            return result;
        }
        // If the digit is 9, it becomes 0, and the carry loops to the next iteration
        result[i] = 0;
    }

    // If the loop finishes without returning, all digits were 9 (e.g., 99 -> 100)
    // We need to free the old result and allocate an array larger by 1
    free(result);
    result = (int*)malloc((digitsSize + 1) * sizeof(int));
    
    // The new array starts with 1, and all subsequent digits are 0
    result[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }
    
    *returnSize = digitsSize + 1;
    return result;
}

