#include <iostream> 
using namespace std; 
struct Node { 
    char data; 
    Node* prev; 
    Node* next; 
}; 
 
Node* head = NULL; 
 
// Function to insert a character at the end 
void insertEnd(char ch) { 
    Node* newNode = new Node; 
    newNode->data = ch; 
    newNode->next = NULL; 
    newNode->prev = NULL; 
 
    if (head == NULL) { 
        head = newNode; 
    } else { 
        Node* temp = head; 
        while (temp->next != NULL) 
            temp = temp->next; 
 
        temp->next = newNode; 
        newNode->prev = temp; 
    } 
} 
 
// Function to display the list 
void display() { 
    Node* temp = head; 
    cout << "Doubly Linked List: "; 
    while (temp != NULL) { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
    cout << endl; 
} 
 
// Function to check palindrome 
bool isPalindrome() { 
    if (head == NULL || head->next == NULL) 
        return true;  
 
    Node* left = head; 
    Node* right = head; 
 
    while (right->next != NULL) 
        right = right->next; 
 
    // Compare characters from both ends 
    while (left != right && right->next != left) { 
        if (left->data != right->data) 
            return false; 
 
        left = left->next; 
        right = right->prev; 
    } 
 
    return true; 
} 
int main() { 
    string str; 
    cout << "Enter a word: "; 
    cin >> str; 
 
    // Create doubly linked list from string 
    for (char ch : str) 
        insertEnd(ch); 
 
    display(); 
 
    if (isPalindrome()) 
        cout << "The given doubly linked list is a palindrome.\n"; 
    else 
        cout << " The given doubly linked list is not a palindrome.\n"; 
 
    return 0; 
}