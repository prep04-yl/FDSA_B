#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = nullptr;
    }
};

class BrowserHistory {
    Node* top;

public:
    BrowserHistory() {
        top = nullptr;
    }

    // Visit a new page
    void visit(string page) {
        Node* newNode = new Node(page);
        newNode->next = top;
        top = newNode;

        cout << "Current Page: " << top->page << endl;
    }

    // Go back
    void back() {
        if (top == nullptr) {
            cout << "No history" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        if (top != nullptr)
            cout << "Current Page: " << top->page << endl;
        else
            cout << "No page" << endl;
    }
};

int main() {
    BrowserHistory browser;

    browser.visit("Google");
    browser.visit("YouTube");
    browser.visit("GitHub");

    browser.back();
    browser.back();

    return 0;
}
