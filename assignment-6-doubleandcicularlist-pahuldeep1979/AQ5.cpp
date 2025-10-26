#include <iostream> 
using namespace std; 
 
class Node { 
public: 
    int data; 
    Node* next; 
 
    Node(int value) { 
        data = value; 
        next = nullptr; 
    } 
}; 
 
bool isCircular(Node* head) { 
    if (head == nullptr) return false;  // empty list not circular 
 
    Node* temp = head->next; 
 
    while (temp != nullptr && temp != head) { 
        temp = temp->next;                   
    } 
 
    return (temp == head);   
} 
 
int main() { 
 
    Node* head1 = new Node(10); 
    Node* second1 = new Node(20); 
    Node* third1 = new Node(30); 
 
    head1->next = second1; 
    second1->next = third1; 
    third1->next = head1;  // circular 
 
    cout << "List 1 is " << (isCircular(head1) ? "Circular" : "Not Circular") << endl; 
 
    Node* head2 = new Node(5); 
    Node* second2 = new Node(15); 
    Node* third2 = new Node(25); 
 
    head2->next = second2; 
    second2->next = third2; 
    third2->next = nullptr;  // not circular 
 
    cout << "List 2 is " << (isCircular(head2) ? "Circular" : "Not Circular") << endl; 
 
return 0; 
} 