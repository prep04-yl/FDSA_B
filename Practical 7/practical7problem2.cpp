#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void arrive(int patient) {
    Node* newNode = new Node;
    newNode->data = patient;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Front patient: " << front->data << endl;
}

void attend() {
    if (front == NULL) {
        cout << "Error: Queue is empty" << endl;
        return;
    }

    Node* temp = front;
    front = front->next;
    delete temp;

    if (front == NULL)
        rear = NULL;

    if (front != NULL)
        cout << "Front patient: " << front->data << endl;
    else
        cout << "Queue is empty" << endl;
}

int main() {
    arrive(101);
    arrive(102);
    arrive(103);

    attend();
    attend();

    arrive(104);

    attend();
    attend();

    return 0;
}
