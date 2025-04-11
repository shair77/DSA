#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head = nullptr;

public:
    void insert(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int val) {
        Node *temp = head, *prev = nullptr;
        while (temp && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Value not found\n";
            return;
        }
        if (!prev) head = temp->next;
        else prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insert(val); break;
            case 2: cout << "Enter value to delete: "; cin >> val; list.remove(val); break;
            case 3: list.display(); break;
        }
    } while (choice != 4);
}
