#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
    }

    void addFirst(string song) {
        Node* newNode = new Node(song);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addLast(string song) {
        Node* newNode = new Node(song);

        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(string currentSong, string newSong) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->song == currentSong) {
                Node* newNode = new Node(newSong);

                newNode->prev = temp;
                newNode->next = temp->next;

                if (temp->next != nullptr)
                    temp->next->prev = newNode;
                else
                    tail = newNode;

                temp->next = newNode;
                return;
            }

            temp = temp->next;
        }
    }

    void removeFirst() {
        if (head == nullptr)
            return;

        Node* temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    int count() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Playlist p;

    p.addFirst("A");
    p.display();

    p.addLast("B");
    p.display();

    p.insertAfter("A", "C");
    p.display();

    cout << "Count: " << p.count() << endl;

    p.removeFirst();
    p.display();

    return 0;
}
