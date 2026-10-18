#include <iostream>
using namespace std;

int main() {
    int table[10], n, id, slot;

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> id;

        slot = id % 10;

        while (table[slot] != -1) {
            slot = (slot + 1) % 10;
        }

        table[slot] = id;
    }

    cout << "\nParking Slots:\n";
    for (int i = 0; i < 10; i++)
        cout << i << ": " << table[i] << endl;

    return 0;
}
