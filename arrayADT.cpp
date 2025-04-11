#include <iostream>
using namespace std;

class ArrayADT {
    int arr[100];  // fixed size for simplicity
    int size;      // current number of elements

public:
    ArrayADT() { size = 0; }

    void insert(int pos, int value) {
        if (size >= 100 || pos > size || pos < 0) {
            cout << "Insertion not possible.\n";
            return;
        }
        for (int i = size; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = value;
        size++;
    }

    void remove(int pos) {
        if (size == 0 || pos < 0 || pos >= size) {
            cout << "Deletion not possible.\n";
            return;
        }
        for (int i = pos; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                return i;
        }
        return -1;  // not found
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    ArrayADT a;
    int choice, pos, val;

    do {
        cout << "\n--- Array ADT Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                a.insert(pos, val);
                break;
            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                a.remove(pos);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                pos = a.search(val);
                if (pos != -1)
                    cout << "Value found at position: " << pos << endl;
                else
                    cout << "Value not found.\n";
                break;
            case 4:
                a.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
