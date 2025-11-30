/*
Given a linked list, determine whether it contains a loop (cycle) using a hash set.
A loop exists if some node’s next pointer points to a previous node in the list.
Input:
1 → 2 → 3 → 4 → 2 (back to node 2)
Output:
true
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;

    Node* current = head;
    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            return true;   // cycle detected
        }
        visited.insert(current);
        current = current->next;
    }
    return false; // no cycle
}

int main() {
    // Creating linked list: 1 → 2 → 3 → 4 → 2 (cycle back to node 2)

    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // Creating the loop

    if (hasCycle(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}

/*
Sample Input (conceptual)
1 → 2 → 3 → 4 → 2  (loop back to node 2)

Sample Output
true
*/