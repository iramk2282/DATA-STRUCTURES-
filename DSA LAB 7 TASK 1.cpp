#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string title;
    float price;
    int edition, pages;
    Node* next;
};

// Stack class
class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push
    void push(string t, float p, int e, int pg) {
        Node* n = new Node();
        n->title = t;
        n->price = p;
        n->edition = e;
        n->pages = pg;

        n->next = top;
        top = n;
    }

    // Pop
    void pop() {
        if (top == NULL) {
            cout << "Stack Empty\n";
            return;
        }

        Node* temp = top;
        cout << "Removed Book: " << top->title << endl;
        top = top->next;
        delete temp;
    }

    // Peek
    void peek() {
        if (top != NULL)
            cout << "Top Book: " << top->title << endl;
    }

    // Display
    void display() {
        Node* temp = top;

        while (temp != NULL) {
            cout << temp->title << " | Price: " << temp->price
                 << " | Edition: " << temp->edition
                 << " | Pages: " << temp->pages << endl;

            temp = temp->next;
        }
    }
};

int main() {

    Stack s;

    // Push 5 books
    s.push("Book1",1000,1,200);
    s.push("Book2",1200,2,250);
    s.push("Book3",1400,3,300);
    s.push("Book4",1600,4,350);
    s.push("Book5",1800,5,400);

    // Top element
    s.peek();

    // Pop 2 books
    s.pop();
    s.pop();

    // Display remaining
    cout << "\nRemaining Books:\n";
    s.display();

    return 0;
}
