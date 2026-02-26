// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    // 1. Corner cases
    if (s == NULL) {
        return false;
    }
    
    size_t len = strlen(s);
    if (len == 0) {
        return true; 
    }
    // Odd length strings cannot possibly be valid pairs
    if (len % 2 != 0) {
        return false;
    }

    // 2. Initialize the stack
    // We can use a Variable Length Array (VLA) since the max depth is 'len'
    char stack[len]; 
    int top = -1;

    // 3. Scan the string from left to right
    for (size_t i = 0; i < len; i++) {
        char c = s[i];
        
        // If it's an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        // If it's a closing bracket
        else {
            // If the stack is empty, we have a closing bracket with no opening pair
            if (top == -1) {
                return false;
            }
            
            char top_char = stack[top];
            
            // Check if the closing bracket matches the top of the stack
            if ((c == ')' && top_char == '(') ||
                (c == '}' && top_char == '{') ||
                (c == ']' && top_char == '[')) {
                top--; // Pop the matched bracket off the stack
            } else {
                return false; // Mismatched bracket types
            }
        }
    }
    
    // 4. Final check
    // If the stack is empty (top == -1), all brackets were properly closed.
    return top == -1;
}