#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* table[10] = {NULL};

void insert(int code) {
    int slot = code % 10;
    Node* temp = new Node{code, table[slot]};
    table[slot] = temp;
}

void display() {
    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        Node* temp = table[i];

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
}

int main() {
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> code;
        insert(code);
    }

    display();
    return 0;
}
