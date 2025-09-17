/* Roll no :1024030982 , assignment completed */
// Q4. Write a program to reverse a linked list.

#include <iostream> 
using namespace std; 
 
// Node structure 
struct Node { 
    int data; 
    Node* next; 
}; 
 
// Function to print list 
void display(Node* head) { 
    Node* temp = head; 
    while (temp != NULL) { 
        cout << temp->data << "->"; 
        temp = temp->next; 
    } 
    cout << "NULL" << endl; 
} 
 
// Function to reverse the linked list 
Node* reverseList(Node* head) { 
    Node* prev = NULL; 
    Node* curr = head; 
    Node* next = NULL; 
 
    while (curr != NULL) { 
        next = curr->next;   // store next node 
        curr->next = prev;   // reverse the link 
        prev = curr;         // move prev forward 
        curr = next;         // move curr forward 
    } 
    return prev; // new head 
} 
 
int main() { 
    // Creating list: 1->2->3->4->NULL 
    Node* head = new Node{1, NULL}; 
    head->next = new Node{2, NULL}; 
    head->next->next = new Node{3, NULL}; 
    head->next->next->next = new Node{4, NULL}; 
 
    cout << "Original List: "; 
    display(head); 
 
    head = reverseList(head); 
 
    cout << "Reversed List: "; 
    display(head); 
 
    return 0; 
}
