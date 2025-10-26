#include <iostream> 
using namespace std; 
 
// Node structure 
class Node { 
public: 
    int data; 
    Node* next; 
 
    Node(int value) { 
        data = value; 
        next = nullptr; 
    } 
}; 
 
// Function to display circular linked list 
void displayCircular(Node* head) { 
    if (head == nullptr) { 
        cout << "List is empty." << endl; 
        return; 
    } 
 
    Node* temp = head; 
 
    // Traverse until we return back to head 
    do { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } while (temp != head); 
 
    // Print head again at the end 
    cout << temp->data << endl; 
} 
 
int main() { 
    // Creating nodes 
    Node* head = new Node(20); 
    Node* second = new Node(100); 
    Node* third = new Node(40); 
    Node* fourth = new Node(80); 
    Node* fifth = new Node(60); 
 
    // Linking nodes circularly 
    head->next = second; 
    second->next = third; 
    third->next = fourth; 
    fourth->next = fifth; 
    fifth->next = head;  // circular link 
 
    // Display 
    displayCircular(head); 
 
    return 0; 
}