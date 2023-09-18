#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }

    // Add a search function to your node class
    node* search(int x) {
        node* ptr = this;
        while (ptr != NULL && ptr->data != x) {
            ptr = ptr->next;
        }
        return ptr;
    }
};

// Function to insert a node at the head
void insertathead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n;
}

// Function to insert a node at the tail
void insertattail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = n;
}

// Function to insert a node between two nodes
// void insertbtw(node* &head, int val, int y) {
//     node* n = new node(val);
//     node* ptr = head;
//     for (int i = 1; i < y - 1; i++) {
//         ptr = ptr->next;
//     }
//     n->next = ptr->next;
//     ptr->next = n;
// }
void insertbtw(node* &head, int val, int y) {
    node* n = new node(val);
    node* ptr = head;
    int len = 0;

    // Calculate the length of the linked list
    while (ptr != NULL) {
        len++;
        ptr = ptr->next;
    }

    if (y <= 1) {
        // If y is 1 or less, insert at the head
        n->next = head;
        head = n;
    } else if (y = len) {
        cout<<"this is present at last node so perform insertatail function will be performed";

        insertattail(head, val);
    } else {
        // Otherwise, insert between nodes
        ptr = head;
        for (int i = 1; i < y - 1; i++) {
            ptr = ptr->next;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}
// Function to delete a node
void deletenode(node* &head, int x) {
    node* ptr = head;
    node* ptr2 = head;
    if (x == 1) {
        ptr2 = ptr2->next;
        head = ptr2;
    }
    else {
        ptr2 = ptr2->next;
        for (int i = 1; i < x - 1; i++) {
            ptr2 = ptr2->next;
            ptr = ptr->next;
        }
        ptr->next = ptr2->next;
    }
}

// Function to display the linked list
void display(node* head) {
    node* ptr = head;
    while (ptr != NULL) {
        cout << "|" << ptr->data << " | " << ptr->next << "| ->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
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
        cout << "5. Display linked list\n";
        cout << "6. Search for a value\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
