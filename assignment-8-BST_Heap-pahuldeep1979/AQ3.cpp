// 3. Write a program for binary search tree (BST) having functions for the following
// operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of BSt 
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// (a) Insert (no duplicates)
Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insertNode(root->left, key);
    else if (key > root->data)
        root->right = insertNode(root->right, key);
    // if equal, do nothing (no duplicates)
    return root;
}

// Helper: find minimum node in subtree
Node* findMinNode(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}

// (b) Delete an existing element
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Found node to delete
        // Case 1: no child or one child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // Case 2: two children
            // Replace with inorder successor (smallest in right subtree)
            Node* succ = findMinNode(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

// (c) Maximum depth (height) of BST
// Returns number of levels in longest path (root alone => 1)
int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + max(l, r);
}

// (d) Minimum depth of BST
// Returns number of levels in shortest root->leaf path
int minDepth(Node* root) {
    if (!root) return 0;

    // If one of the subtrees is null, we must take the depth of the other subtree.
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);

    // Both children exist
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Utility: inorder traversal (sorted order)
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

// Clean up tree (post-order delete)
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;

    // Sample insertions
    int values[] = {20, 8, 22, 4, 12, 10, 14};
    for (int v : values)
        root = insertNode(root, v);

    cout << "BST (In-order after inserts): ";
    inorderPrint(root);
    cout << "\n";

    cout << "Maximum depth: " << maxDepth(root) << "\n";
    cout << "Minimum depth: " << minDepth(root) << "\n\n";

    // Delete a node with two children (8), and a leaf (22)
    cout << "Delete 8\n";
    root = deleteNode(root, 8);
    cout << "BST (In-order): ";
    inorderPrint(root);
    cout << "\n";
    cout << "Maximum depth: " << maxDepth(root) << "\n";
    cout << "Minimum depth: " << minDepth(root) << "\n\n";

    cout << "Delete 22\n";
    root = deleteNode(root, 22);
    cout << "BST (In-order): ";
    inorderPrint(root);
    cout << "\n";
    cout << "Maximum depth: " << maxDepth(root) << "\n";
    cout << "Minimum depth: " << minDepth(root) << "\n\n";

    // Try deleting a non-existing element
    cout << "Delete 100 (not present)\n";
    root = deleteNode(root, 100);
    cout << "BST (In-order): ";
    inorderPrint(root);
    cout << "\n";

    // Free memory before exit
    freeTree(root);
    return 0;
}

/*Using the sample insert sequence 20, 8, 22, 4, 12, 10, 14 the program prints:
BST (In-order after inserts): 4 8 10 12 14 20 22
Maximum depth: 4
Minimum depth: 2

Delete 8
BST (In-order): 4 10 12 14 20 22
Maximum depth: 4
Minimum depth: 2

Delete 22
BST (In-order): 4 10 12 14 20
Maximum depth: 4
Minimum depth: 2

Delete 100 (not present)
BST (In-order): 4 10 12 14 20

*/
