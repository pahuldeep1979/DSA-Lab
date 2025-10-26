#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* prev; 
    Node* next; 
}; 
 
Node* head = NULL; 
 
// Function to insert at end 
void insertEnd(int val) { 
    Node* newNode = new Node; 
    newNode->data = val; 
    newNode->next = NULL; 
    newNode->prev = NULL; 
 
    if (head == NULL) 
        head = newNode; 
    else { 
        Node* temp = head; 
        while (temp->next != NULL) 
            temp = temp->next; 
        temp->next = newNode; 
        newNode->prev = temp; 
    } 
} 
 
// Function to find size 
int getSize() { 
    int count = 0; 
    Node* temp = head; 
    while (temp != NULL) { 
        count++; 
        temp = temp->next; 
    } 
    return count; 
} 
 
// Display function 
void display() { 
    Node* temp = head; 
    cout << "Doubly Linked List: "; 
    while (temp != NULL) { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
    cout << endl; 
} 
 
int main() { 
    insertEnd(10); 
    insertEnd(20); 
    insertEnd(30); 
    insertEnd(40); 
 
    display(); 
    cout << "Size of Doubly Linked List = " << getSize() << endl; 
    return 0; 
} 