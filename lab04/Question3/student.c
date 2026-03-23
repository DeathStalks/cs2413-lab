#include <stddef.h>

/*
Question 3: Sum Root to Leaf Numbers

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers.

A leaf node is a node with no children.

Examples:

Example 1:
Input:
        1
       / \
      2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents 12.
The root-to-leaf path 1->3 represents 13.
12 + 13 = 25.

Example 2:
Input:
          4
         / \
        9   0
       / \
      5   1
Output: 1026
Explanation:
The numbers are 495, 491, and 40.
495 + 491 + 40 = 1026.

Function to complete:
    int sumNumbers(struct TreeNode* root);

Note:
- Each node stores a digit from 0 to 9.
- If the tree is empty, return 0.
- Build the current number as you move from root to leaf.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumNumbers(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }


    struct TreeNode* nodeStack[2000];
    int sumStack[2000];
    int top = -1; // Stack pointer

    int totalSum = 0;

    // Push the root node and its value onto the stacks
    top++;
    nodeStack[top] = root;
    sumStack[top] = root->val;

    // Loop until our stack is empty
    while (top >= 0) {
        // Pop the top elements
        struct TreeNode* currentNode = nodeStack[top];
        int currentSum = sumStack[top];
        top--;

        // If we reached a leaf, add the path's sum to our total
        if (currentNode->left == NULL && currentNode->right == NULL) {
            totalSum += currentSum;
        }

        // Push the right child onto the stack if it exists
        // (We push right first so left is processed first, mimicking standard DFS)
        if (currentNode->right != NULL) {
            top++;
            nodeStack[top] = currentNode->right;
            sumStack[top] = (currentSum * 10) + currentNode->right->val;
        }

        // Push the left child onto the stack if it exists
        if (currentNode->left != NULL) {
            top++;
            nodeStack[top] = currentNode->left;
            sumStack[top] = (currentSum * 10) + currentNode->left->val;
        }
    }

    return totalSum;
}