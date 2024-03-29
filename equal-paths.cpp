#ifndef RECCHECK
#include <iostream>
#endif

#include "equal-paths.h"
using namespace std;

// Helper function
int getHeight(Node* root);

// Function to check if all paths from root to leaves are of equal length
bool equalPaths(Node* root) {
    if (!root) return true;

    Node* leftNode = root->left, *rightNode = root->right;

    if (leftNode && rightNode) {
        return getHeight(leftNode) == getHeight(rightNode);
    }
    else if (leftNode) {
        return equalPaths(leftNode);
    }
    else if (rightNode) {
        return equalPaths(rightNode);
    }
    return true;
}

// Get height of a tree
int getHeight(Node* root) {
    if (!root) return 0;
    Node* leftNode = root->left, *rightNode = root->right;
    int leftH = getHeight(leftNode), rightH = getHeight(rightNode);
    return leftH >= rightH ? ++leftH : ++rightH;
}
