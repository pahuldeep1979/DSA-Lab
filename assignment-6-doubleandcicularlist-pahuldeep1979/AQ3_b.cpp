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
 
// Function to count nodes in circular linked list  
int getSize(Node* head) { 
    if (head == nullptr) return 0; 
 
    int count = 0; 
    Node* temp = head; 
 
    do { 
        count++; 
        temp = temp->next; 
    } while (temp != head); 
 
    return count; 
} 
 
int main() { 
    // Create nodes 
    Node* head = new Node(20); 
    Node* second = new Node(100); 
    Node* third = new Node(40); 
    Node* fourth = new Node(80); 
    Node* fifth = new Node(60); 
 
    // Link nodes circularly 
    head->next = second; 
    second->next = third; 
    third->next = fourth; 
    fourth->next = fifth; 
    fifth->next = head;  // circular link 
 
    // Find size 
    cout << "Size of circular linked list: " << getSize(head) << endl; 
 
    return 0; 
} 