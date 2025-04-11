#include <iostream>
#include <string>
using namespace std;

class MyString {
    string str;

public:
    void insert(int pos, char ch) {
        if (pos >= 0 && pos <= str.size())
            str.insert(pos, 1, ch);
        else
            cout << "Invalid position.\n";
    }

    void remove(int pos) {
        if (pos >= 0 && pos < str.size())
            str.erase(pos, 1);
        else
            cout << "Invalid position.\n";
    }

    void search(char ch) {
        int index = str.find(ch);
        if (index != string::npos)
            cout << "Character found at position: " << index << endl;
        else
            cout << "Character not found.\n";
    }

    void display() {
        cout << "Current string: " << str << endl;
    }
};

int main() {
    MyString s;
    int choice, pos;
    char ch;

    do {
        cout << "\n--- String ADT Menu ---\n";
        cout << "1. Insert character\n2. Delete character\n3. Search character\n4. Display string\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter position and character: ";
                cin >> pos >> ch;
                s.insert(pos, ch);
                break;
            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                s.remove(pos);
                break;
            case 3:
                cout << "Enter character to search: ";
                cin >> ch;
                s.search(ch);
                break;
            case 4:
                s.display();
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
