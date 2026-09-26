#include <iostream>
using namespace std;

// ---------- SINGLY CIRCULAR LINKED LIST ----------

struct SNode {
    int data;
    SNode* next;

    SNode(int x) {
        data = x;
        next = nullptr;
    }
};

class SinglyCircular {
    SNode* head;

public:
    SinglyCircular() {
        head = nullptr;
    }

    void insert(int value, int position) {
        SNode* newNode = new SNode(value);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }

        // Insert at beginning
        if (position == 1) {
            SNode* temp = head;

            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
            return;
        }

        SNode* temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove(int value) {
        if (head == nullptr)
            return;

        // Only one node
        if (head->data == value && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        // Remove head
        if (head->data == value) {
            SNode* last = head;

            while (last->next != head)
                last = last->next;

            SNode* temp = head;
            head = head->next;
            last->next = head;

            delete temp;
            return;
        }

        SNode* temp = head;

        while (temp->next != head) {
            if (temp->next->data == value) {
                SNode* del = temp->next;
                temp->next = del->next;
                delete del;
                return;
            }

            temp = temp->next;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }

        SNode* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};


// ---------- DOUBLY CIRCULAR LINKED LIST ----------

struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int x) {
        data = x;
        prev = next = nullptr;
    }
};

class DoublyCircular {
    DNode* head;

public:
    DoublyCircular() {
        head = nullptr;
    }

    void insert(int value, int position) {
        DNode* newNode = new DNode(value);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        // Insert at beginning
        if (position == 1) {
            DNode* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }

        DNode* temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void remove(int value) {
        if (head == nullptr)
            return;

        DNode* temp = head;

        do {
            if (temp->data == value) {

                // Only node
                if (temp->next == temp) {
                    delete temp;
                    head = nullptr;
                    return;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;

                delete temp;
                return;
            }

            temp = temp->next;

        } while (temp != head);
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty\n";
            return;
        }

        DNode* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};


// ---------- MAIN ----------

int main() {

    SinglyCircular s;
    DoublyCircular d;

    cout << "Singly Circular:\n";

    s.insert(1, 1);
    s.display();

    s.insert(2, 2);
    s.display();

    s.insert(3, 2);
    s.display();

    s.remove(2);
    s.display();


    cout << "\nDoubly Circular:\n";

    d.insert(1, 1);
    d.display();

    d.insert(2, 2);
    d.display();

    d.insert(3, 2);
    d.display();

    d.remove(2);
    d.display();

    return 0;
}
