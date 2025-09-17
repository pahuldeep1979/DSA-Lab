/* Roll no :1024030982 , assignment completed */
//  Develop a menu driven program for the following operations on a Singly Linked List.
#include<iostream> 
using namespace std; 
struct Node{ 
    int data; 
    Node* next; 
}; 
Node* head=NULL; //global head pointer 
// Insert at beginning 
void insertbegin(int value){ 
    Node* newNode= new Node(); 
    newNode->data=value; 
    newNode->next=head; 
    head=newNode; 
    cout << value << " inserted at beginning.\n"; 
} 
//Insert at end 
void insertend(int value){ 
    Node* newNode= new Node(); 
    newNode->data=value; 
    newNode->next=NULL; //since it will be last node 
    if(head==NULL) head=newNode; 
    else{ 
        Node* temp=head; 
        while(temp->next!=NULL) temp=temp->next; 
        temp->next=newNode; 
    } 
    cout<< value<<"inserted at end"<<endl; 
} 
void insertspecific(int key, int value, bool after){ 
    Node* newNode = new Node(); 
    newNode->data = value; 
    Node* temp = head; 
 
    // If inserting before head 
    if (!after && head->data == key) { 
        newNode->next = head; 
        head = newNode; 
        cout << value << " inserted before " << key << ".\n"; 
        return; 
    } 
 
    while (temp != NULL) { 
        if (after && temp->data == key) { 
            newNode->next = temp->next; 
            temp->next = newNode; 
            cout << value << " inserted after " << key << ".\n"; 
            return; 
        } else if (!after && temp->next != NULL && temp->next->data == key) { 
            newNode->next = temp->next; 
            temp->next = newNode; 
            cout << value << " inserted before " << key << ".\n"; 
            return; 
        } 
        temp = temp->next; 
    } 
 
    cout << "Key " << key << " not found!\n"; 
} 
void deletebegin(){ 
    Node* temp=head; 
    head=head->next; 
    cout << "Deleted: "<<temp->data<<endl; 
    delete temp; 
} 
void deleteend(){ 
    if(head->next==NULL){     // only one node there 
        cout<<"Deleted: "<< head->data<<endl; 
        delete head; 
        head=NULL; 
        return; 
    } 
    Node* temp=head; 
    while(temp->next->next!=NULL) temp=temp->next; 
    cout<<"Deleted: "<<temp->next->data<<endl; 
    delete temp->next; 
    temp->next=NULL; 
} 
void deletespecific(int key){ 
     if (head->data == key) {   // if node to delete is head 
        Node* temp = head; 
        head = head->next; 
        cout << "Deleted: " << temp->data << endl; 
        delete temp; 
        return; 
    } 
    Node* temp=head; 
    while(temp->next->data!=key && temp->next!=NULL){ 
          temp=temp->next; 
    } 
    if(temp->next==NULL) cout<< key << "not found\n"; 
    else{ 
        Node* del=temp->next; 
        temp->next = temp->next->next; 
        cout << "Deleted: " << del->data << endl; 
        delete del; 
    } 
} 
void searchNode(int key){ 
    Node* temp=head; int pos=1; 
    while(temp!=NULL){ 
        if(temp->data==key) {cout<< key << "found at position " << pos << endl; 
        return; 
    } 
   temp=temp->next; 
   pos++; 
} 
} 
void display(){ 
    Node* temp= head; 
    while(temp!=NULL){ 
        cout<< temp->data<<"->"; 
        temp=temp->next; 
    } 
cout<<"NULL\n"; 
} 
int main(){ 
    int choice, value, key; 
    bool after; 
 
    do { 
        cout << "\n--- Singly Linked List Menu ---\n"; 
        cout << "1. Insert at Beginning\n"; 
        cout << "2. Insert at End\n"; 
        cout << "3. Insert Before a Node\n"; 
        cout << "4. Insert After a Node\n"; 
        cout << "5. Delete from Beginning\n"; 
        cout << "6. Delete from End\n"; 
        cout << "7. Delete Specific Node\n"; 
        cout << "8. Search for a Node\n"; 
        cout << "9. Display List\n"; 
        cout << "0. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter value: "; 
                cin >> value; 
                insertbegin(value); 
                break; 
            case 2: 
                cout << "Enter value: "; 
                cin >> value; 
                insertend(value); 
                break; 
            case 3: 
                cout << "Enter key (node value to insert before): "; 
                cin >> key; 
                cout << "Enter new value: "; 
                cin >> value; 
                insertspecific(key, value, false); 
                break; 
            case 4: 
                cout << "Enter key (node value to insert after): "; 
                cin >> key; 
                cout << "Enter new value: "; 
                cin >> value; 
                insertspecific(key, value, true); 
                break; 
            case 5: 
                deletebegin(); 
                break; 
            case 6: 
                deleteend(); 
                break; 
            case 7: 
                cout << "Enter node value to delete: "; 
                cin >> key; 
                deletespecific(key); 
                break; 
            case 8: 
                cout << "Enter node value to search: "; 
                cin >> key; 
                searchNode(key); 
                break; 
            case 9: 
                display(); 
                break; 
            case 0: 
                cout << "Exiting...\n"; 
                break; 
            default: 
                cout << "Invalid choice!\n"; 
        } 
    } while (choice != 0); 
 
    return 0; 
}
