#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Function to display the doubly linked list
   void display() {
    Node* current = head;
    while (current) {
        cout << "(";
        if (current->prev) {
            cout << current->prev << " <-> ";
        } else {
            cout << "NULL <-> ";
        }
        cout << current->data << " <-> ";
        if (current->next) {
            cout << current->next;
        } else {
            cout << "NULL";
        }
        cout << ") ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

    // Function to delete a node by value
    void deleteNode(int val) {
        Node* current = head;
        while (current) {
            if (current->data == val) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at tail\n";
        cout << "3. Delete a node\n";
        cout << "4. Display doubly linked list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at the head: ";
            cin >> val;
            dll.insertAtHead(val);
            break;
        case 2:
            cout << "Enter value to insert at the tail: ";
            cin >> val;
            dll.insertAtTail(val);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> val;
            dll.deleteNode(val);
            break;
        case 4:
            cout << "Doubly Linked List: ";
            dll.display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
