/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 * bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 * make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Recursive helper function
// Returns the height of the tree if it is a valid AVL tree.
// Returns -1 if it violates the BST property or the height-balance property.
static int checkAVLHelper(struct TreeNode* node, struct TreeNode* minNode, struct TreeNode* maxNode) {
    // Base case: an empty tree is balanced and has height 0
    if (node == NULL) {
        return 0;
    }

    // 1) Check strict BST property using bounds (no duplicates allowed)
    if (minNode != NULL && node->val <= minNode->val) {
        return -1;
    }
    if (maxNode != NULL && node->val >= maxNode->val) {
        return -1;
    }

    // 2) Recursively get the height of the left subtree
    // The current node's value becomes the new maximum bound for the left subtree
    int leftHeight = checkAVLHelper(node->left, minNode, node);
    if (leftHeight == -1) {
        return -1; // Propagate failure up
    }

    // 3) Recursively get the height of the right subtree
    // The current node's value becomes the new minimum bound for the right subtree
    int rightHeight = checkAVLHelper(node->right, node, maxNode);
    if (rightHeight == -1) {
        return -1; // Propagate failure up
    }

    // 4) Check height balance for the current node
    int heightDiff = leftHeight - rightHeight;
    if (heightDiff < -1 || heightDiff > 1) { // Equivalent to abs(heightDiff) > 1
        return -1;
    }

    // 5) If valid, return the height of the current subtree
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isAVL(struct TreeNode* root) {
    // If the helper returns anything other than -1, it's a valid AVL tree
    return checkAVLHelper(root, NULL, NULL) != -1;
}