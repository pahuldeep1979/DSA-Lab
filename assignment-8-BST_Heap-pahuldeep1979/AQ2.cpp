// 2. Implement following functions for Binary Search Trees
// (a) Search a given item (Recursive & Non-Recursive)
// (b) Maximum element of the BST
// (c) Minimum element of the BST
// (d) In-order successor of a given node the BST
// (e) In-order predecessor of a given node the BST
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// Insert into BST (recursive)
Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insertNode(root->left, key);
    else if (key > root->data) root->right = insertNode(root->right, key);
    // if equal, do nothing (no duplicates)
    return root;
}

// (a) Search - Recursive
Node* searchRecursive(Node* root, int key) {
    if (!root) return nullptr;
    if (root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) Search - Non-Recursive (Iterative)
Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->data == key) return cur;
        cur = (key < cur->data) ? cur->left : cur->right;
    }
    return nullptr;
}

// (b) Maximum element of BST
Node* findMax(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur;
}

// (c) Minimum element of BST
Node* findMin(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}

// Helper: find node by key (returns nullptr if not found)
Node* findNode(Node* root, int key) {
    return searchIterative(root, key);
}

// (d) In-order successor of a given node (by key)
// If node has right child -> successor is min in right subtree.
// Else, walk from root and remember the last node for which target is in left subtree.
Node* inorderSuccessor(Node* root, int key) {
    Node* target = findNode(root, key);
    if (!target) return nullptr;

    // Case 1: right subtree exists
    if (target->right) {
        return findMin(target->right);
    }

    // Case 2: no right subtree, find deepest ancestor for which target is in left subtree
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (key < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->data) {
            cur = cur->right;
        } else break;
    }
    return succ;
}

// (e) In-order predecessor of a given node (by key)
// If node has left child -> predecessor is max in left subtree.
// Else, walk from root and remember the last node for which target is in right subtree.
Node* inorderPredecessor(Node* root, int key) {
    Node* target = findNode(root, key);
    if (!target) return nullptr;

    if (target->left) {
        return findMax(target->left);
    }

    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (key > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pred;
}

// Inorder traversal for display (sorted order)
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    // Build a sample BST:
    // Insert sequence: 20, 8, 22, 4, 12, 10, 14
    Node* root = nullptr;
    int vals[] = {20, 8, 22, 4, 12, 10, 14};
    for (int v : vals) root = insertNode(root, v);

    cout << "BST (In-order): ";
    inorderPrint(root);
    cout << "\n\n";

    // (a) Search tests
    int keysToSearch[] = {10, 15};
    for (int k : keysToSearch) {
        Node* r = searchRecursive(root, k);
        cout << "searchRecursive(" << k << "): "
             << (r ? "Found" : "Not Found") << "\n";
    }
    for (int k : keysToSearch) {
        Node* r = searchIterative(root, k);
        cout << "searchIterative(" << k << "): "
             << (r ? "Found" : "Not Found") << "\n";
    }
    cout << "\n";

    // (b) Maximum
    Node* mx = findMax(root);
    cout << "Maximum element in BST: " << (mx ? mx->data : -1) << "\n";

    // (c) Minimum
    Node* mn = findMin(root);
    cout << "Minimum element in BST: " << (mn ? mn->data : -1) << "\n\n";

    // (d) In-order successor (examples)
    int succKeys[] = {8, 10, 14, 22}; // include a key with no successor
    for (int k : succKeys) {
        Node* s = inorderSuccessor(root, k);
        if (s) cout << "Inorder Successor of " << k << " is " << s->data << "\n";
        else cout << "Inorder Successor of " << k << " does not exist\n";
    }
    cout << "\n";

    // (e) In-order predecessor (examples)
    int predKeys[] = {8, 10, 4, 20}; // include a key with no predecessor
    for (int k : predKeys) {
        Node* p = inorderPredecessor(root, k);
        if (p) cout << "Inorder Predecessor of " << k << " is " << p->data << "\n";
        else cout << "Inorder Predecessor of " << k << " does not exist\n";
    }

    return 0;
}

// output produced by the above program (with the sample BST built from 20, 8, 22, 4, 12, 10, 14):
// BST (In-order): 4 8 10 12 14 20 22

// searchRecursive(10): Found
// searchRecursive(15): Not Found
// searchIterative(10): Found
// searchIterative(15): Not Found

// Maximum element in BST: 22
// Minimum element in BST: 4

// Inorder Successor of 8 is 10
// Inorder Successor of 10 is 12
// Inorder Successor of 14 is 20
// Inorder Successor of 22 does not exist

// Inorder Predecessor of 8 is 4
// Inorder Predecessor of 10 is 8
// Inorder Predecessor of 4 does not exist
// Inorder Predecessor of 20 is 14

