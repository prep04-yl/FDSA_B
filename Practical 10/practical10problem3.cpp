#include <iostream>
using namespace std;

int table[10];

void insert(int id) {
    int h1 = id % 10;
    int h2 = 7 - (id % 7);
    int i = 0;
    int slot;

    while (i < 10) {
        slot = (h1 + i * h2) % 10;

        if (table[slot] == -1) {
            table[slot] = id;
            return;
        }

        i++;
    }

    cout << "Hash table is full. Cannot insert " << id << endl;
}

void display() {
    for (int i = 0; i < 10; i++)
        cout << i << ": " << table[i] << endl;
}

int main() {
    int n, id;

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;
        insert(id);
    }

    cout << "\nHash Table:\n";
    display();

    return 0;
}
