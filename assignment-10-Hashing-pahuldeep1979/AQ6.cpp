/*
You are given a binary tree (not a binary search tree). Write a program to check if
the tree contains any duplicate node values using hash set.
Your task is to:
1. Return true (or print "Duplicates Found") if there exists at least one duplicate value.
2. Otherwise, return false (or print "No Duplicates").
*/
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// Helper recursive function
bool checkDuplicates(Node* root, unordered_set<int> &seen) {
    if (root == nullptr)
        return false;

    // If value already seen → duplicate found
    if (seen.find(root->data) != seen.end()) {
        return true;
    }

    // Insert the value
    seen.insert(root->data);

    // Recur for left and right subtree
    return checkDuplicates(root->left, seen) ||
           checkDuplicates(root->right, seen);
}

bool containsDuplicates(Node* root) {
    unordered_set<int> seen;
    return checkDuplicates(root, seen);
}

int main() {
    /*
        Example Binary Tree (NOT BST):

                5
               / \
              3   8
             / \   \
            2   3   8     ← duplicates (3, 8)
    */

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(3); // duplicate
    root->right->right = new Node(8); // duplicate

    if (containsDuplicates(root))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";

    return 0;
}

/*
Sample Output
Duplicates Found

*/