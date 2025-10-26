#include<iostream> 
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Function to create new node
Node *createNode(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        head->next = head; // circular
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    cout << "Inserted " << val << " at beginning.\n";
}

// Insert at end
void insertAtEnd(int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Inserted " << val << " at end.\n";
}

// Insert after a specific node
void insertAfter(int key, int val)
{
    if (head == NULL)
    {
        cout << "List empty!\n";
        return;
    }
    Node *temp = head;
    do
    {
        if (temp->data == key)
        {
            Node *newNode = createNode(val);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << " after " << key << ".\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node " << key << " not found.\n";
}

// Delete a specific node
void deleteNode(int key)
{
    if (head == NULL)
    {
        cout << "List empty!\n";
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    // If head node to be deleted
    if (head->data == key)
    {
        Node *last = head;
        while (last->next != head)
            last = last->next;
        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            last->next = head->next;
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Deleted " << key << ".\n";
        return;
    }

    // For other nodes
    do
    {
        prev = curr;
        curr = curr->next;
        if (curr->data == key)
        {
            prev->next = curr->next;
            delete curr;
            cout << "Deleted " << key << ".\n";
            return;
        }
    } while (curr != head);

    cout << "Node " << key << " not found.\n";
}

// Search for a node
void searchNode(int key)
{
    if (head == NULL)
    {
        cout << "List empty!\n";
        return;
    }
    Node *temp = head;
    int pos = 1;
    do
    {
        if (temp->data == key)
        {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    cout << "Node " << key << " not found.\n";
}

// Display list
void display()
{
    if (head == NULL)
    {
        cout << "List empty!\n";
        return;
    }
    Node *temp = head;
    cout << "Circular Linked List: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main menu
int main()
{
    int choice, val, key;
    do
    {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n";
        cout << "4. Delete Node\n5. Search Node\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            insertAfter(key, val);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> val;
            deleteNode(val);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(val);
            break;
        case 6:
            display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}