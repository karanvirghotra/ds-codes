#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = this; // Initialize 'next' to point to itself
    }

    // Add a search function to your node class
    node* search(int x) {
        node* ptr = this;
        do {
            if (ptr->data == x) {
                return ptr;
            }
            ptr = ptr->next;
        } while (ptr != this);
        return NULL; // Return NULL if the value is not found
    }
};

// Function to insert a node at the head
void insertathead(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        n->next = n; // If the list is empty, make the new node point to itself
    } else {
        node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = n; // Update the last node to point to the new node
        n->next = head; // Make the new node point to the head
    }
    head = n; // Update the head to the new node
}

// Function to insert a node at the tail
void insertattail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        n->next = n; // If the list is empty, make the new node point to itself
        head = n; // Update the head to the new node
    } else {
        node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = n; // Update the last node to point to the new node
        n->next = head; // Make the new node point to the head
    }
}

// Function to insert a node between two nodes
void insertbtw(node* &head, int val, int y) {
    node* n = new node(val);
    node* ptr = head;
    while (ptr->next != head) {
        if (ptr->data == y) {
            n->next = ptr->next; // Make the new node point to the next node
            ptr->next = n; // Update the current node to point to the new node
            return;
        }
        ptr = ptr->next;
    }
    // If the value 'y' is not found, insert the node at the head
    insertathead(head, val);
}

// Function to delete a node
void deletenode(node* &head, int x) {
    if (head == NULL) {
        return; // Nothing to delete if the list is empty
    }
    
    node* curr = head;
    node* prev = NULL;
    
    do {
        if (curr->data == x) {
            if (prev == NULL) {
                // If the node to delete is the head node
                node* tail = head;
                while (tail->next != head) {
                    tail = tail->next;
                }
                head = head->next; // Move the head to the next node
                tail->next = head; // Update the last node to point to the new head
            } else {
                prev->next = curr->next; // Update the previous node to skip the current node
            }
            delete curr; // Delete the current node
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

// Function to display the circular linked list
void display(node* head) {
    if (head == NULL) {
        cout << "Circular Linked List is empty." << endl;
        return;
    }
    
    node* ptr = head;
    do {
        cout << "|" << ptr->data << " | -> ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << " (Head)" << endl;
}

int main() {
    node* head = NULL;
    int choice;
    int n, x, y;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at tail\n";
        cout << "3. Insert between nodes\n";
        cout << "4. Delete a node\n";
        cout << "5. Display circular linked list\n";
        cout << "6. Search for a value\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
 {
        case 1:
            cout << "Enter value to insert at the head: ";
            cin >> x;
            insertathead(head, x);
            break;
        case 2:
            cout << "Enter value to insert at the tail: ";
            cin >> x;
            insertattail(head, x);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> x;
            cout << "Enter position to insert at: ";
            cin >> y;
            insertbtw(head, x, y);
            break;
        case 4:
            cout << "Enter position to delete: ";
            cin >> x;
            deletenode(head, x);
            break;
        case 5:
            cout << "Linked List: ";
            display(head);
            break;
        case 6:
            cout << "Enter value to search for: ";
            cin >> x;
            if (head->search(x) != NULL) {
                cout << "Value found in the linked list." << endl;
            } else {
                cout << "Value not found in the linked list." << endl;
            }
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}