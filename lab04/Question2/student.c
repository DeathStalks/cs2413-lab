#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }


    struct TreeNode* queue[4096];
    int head = 0;
    int tail = 0;

    // Enqueue the initial pair to compare: the left and right children of the root
    queue[tail++] = root->left;
    queue[tail++] = root->right;

    while (head < tail) {
        // Dequeue a pair of nodes
        struct TreeNode* t1 = queue[head++];
        struct TreeNode* t2 = queue[head++];

        // If both are NULL, this branch is symmetric so far; continue checking the rest
        if (t1 == NULL && t2 == NULL) {
            continue;
        }

        // If only one is NULL, or if their values don't match, it's not symmetric
        if (t1 == NULL || t2 == NULL || t1->val != t2->val) {
            return false;
        }

        // Enqueue the next pairs in mirroring order.
        // Pair 1: outer branches
        queue[tail++] = t1->left;
        queue[tail++] = t2->right;

        // Pair 2: inner branches
        queue[tail++] = t1->right;
        queue[tail++] = t2->left;
    }

    return true;
}