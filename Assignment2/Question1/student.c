/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 * struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 * make run1
 */

#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    // Traverse the tree until we hit a NULL pointer (leaf) or find the target
    while (root != NULL) {
        if (target == root->val) {
            return root; // Target found, return the pointer to this node
        } else if (target < root->val) {
            root = root->left; // Target is smaller, search the left subtree
        } else {
            root = root->right; // Target is larger, search the right subtree
        }
    }
    
    // If the loop finishes without returning, the target isn't in the tree
    return NULL;
}