/* Roll no :1024030982 , assignment completed */
// Q3.Write a program to find the middle of a linked list.

#include <iostream> 
using namespace std; 
 
// Node structure 
struct Node { 
    int data; 
    Node* next; 
}; 
 
// Function to print the list 
void display(Node* head) { 
    Node* temp = head; 
    while (temp != NULL) { 
        cout << temp->data; 
        if (temp->next != NULL) cout << "->"; 
        temp = temp->next; 
    } 
    cout << endl; 
} 
 
// Function to find middle node 
void findMiddle(Node* head) { 
    if (head == NULL) { 
        cout << "List is empty!" << endl; 
        return; 
    } 
 
    Node* slow = head; 
    Node* fast = head; 
 
    while (fast != NULL && fast->next != NULL) { 
        slow = slow->next;         // move by 1 
        fast = fast->next->next;   // move by 2 
    } 
 
    cout << "Middle element: " << slow->data << endl; 
} 
 
int main() { 
    // Creating list: 1->2->3->4->5 
    Node* head = new Node{1, NULL}; 
    head->next = new Node{2, NULL}; 
    head->next->next = new Node{3, NULL}; 
    head->next->next->next = new Node{4, NULL}; 
    head->next->next->next->next = new Node{5, NULL}; 
 
    cout << "Linked List: "; 
    display(head); 
 
    findMiddle(head); 
 
    return 0; 
}
