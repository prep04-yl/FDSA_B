#include <iostream>
using namespace std;

int q[100], front = 0, rear = -1, n;

void join(int token) {
    if (rear == n - 1) {
        cout << "Error: Queue is full\n";
        return;
    }

    q[++rear] = token;
    cout << "Front token: " << q[front] << endl;
}

void serve() {
    if (front > rear) {
        cout << "Error: Queue is empty\n";
        return;
    }

    front++;

    if (front <= rear)
        cout << "Front token: " << q[front] << endl;
    else
        cout << "Queue is empty\n";
}

int main() {
    cout << "Enter queue size: ";
    cin >> n;

    join(101);
    join(102);
    join(103);

    serve();
    serve();

    join(104);
    join(105);

    return 0;
}
