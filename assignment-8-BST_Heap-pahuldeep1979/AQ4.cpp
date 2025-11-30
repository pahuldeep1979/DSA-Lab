// 4. Write a program to determine whether a given binary tree is a BST or not.
#include <iostream>
#include <climits>   // for LLONG_MIN, LLONG_MAX
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
}

// Helper to create nodes quickly
Node* newNode(int v) {
    return new Node(v);
}

// -----------------------------
// Method A: Min/Max bounds check
// Each node must satisfy: minAllowed < node->data < maxAllowed
// -----------------------------
bool isBST_bounds(Node* root, long long minAllowed, long long maxAllowed) {
    if (!root) return true;
    if (root->data <= minAllowed || root->data >= maxAllowed) return false;
    return isBST_bounds(root->left, minAllowed, root->data) &&
           isBST_bounds(root->right, root->data, maxAllowed);
}

bool isBST_usingBounds(Node* root) {
    return isBST_bounds(root, LLONG_MIN, LLONG_MAX);
}

// -----------------------------
// Method B: Inorder traversal check
// Inorder traversal of BST yields a strictly increasing sequence
// -----------------------------
bool inorderCheck(Node* root, long long &prev) {
    if (!root) return true;
    if (!inorderCheck(root->left, prev)) return false;
    if (root->data <= prev) return false;
    prev = root->data;
    return inorderCheck(root->right, prev);
}

bool isBST_usingInorder(Node* root) {
    long long prev = LLONG_MIN;
    return inorderCheck(root, prev);
}

// Utility: delete tree to avoid leaks
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Demo main: constructs 2 trees (one BST, one not) and checks them
int main() {
    // Example 1: A valid BST
    //       20
    //      /  \
    //     10  30
    //    /  \   \
    //   5   15   40
    Node* bst = newNode(20);
    bst->left = newNode(10);
    bst->right = newNode(30);
    bst->left->left = newNode(5);
    bst->left->right = newNode(15);
    bst->right->right = newNode(40);

    cout << "Tree 1 (should be BST):\n";
    cout << "Using bounds method:  " << (isBST_usingBounds(bst) ? "BST" : "Not BST") << "\n";
    cout << "Using inorder method:  " << (isBST_usingInorder(bst) ? "BST" : "Not BST") << "\n\n";

    // Example 2: Not a BST
    //       20
    //      /  \
    //     30  10   <-- children violate BST property
    Node* notbst = newNode(20);
    notbst->left = newNode(30);
    notbst->right = newNode(10);

    cout << "Tree 2 (should NOT be BST):\n";
    cout << "Using bounds method:  " << (isBST_usingBounds(notbst) ? "BST" : "Not BST") << "\n";
    cout << "Using inorder method:  " << (isBST_usingInorder(notbst) ? "BST" : "Not BST") << "\n";

    // cleanup
    freeTree(bst);
    freeTree(notbst);
    return 0;
}

/*
Tree 1 (should be BST):
Using bounds method:  BST
Using inorder method:  BST

Tree 2 (should NOT be BST):
Using bounds method:  Not BST
Using inorder method:  Not BST

*/