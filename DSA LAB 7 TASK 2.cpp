#include <iostream>
using namespace std;

// -------- Inventory Class --------
class Inventory {
    int serialNum, manufactYear, lotNum;

public:
    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    void display() {
        cout << "Serial No: " << serialNum
             << " | Year: " << manufactYear
             << " | Lot No: " << lotNum << endl;
    }
};

// -------- Node for Linked List --------
struct Node {
    Inventory part;
    Node* next;
};

// -------- Stack Class --------
class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(Inventory p) {
        Node* n = new Node();
        n->part = p;
        n->next = top;
        top = n;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "\nPart removed:\n";
        temp->part.display();

        top = top->next;
        delete temp;
    }

    void display() {
        Node* temp = top;

        cout << "\nRemaining Parts in Stack:\n";
        while (temp != NULL) {
            temp->part.display();
            temp = temp->next;
        }
    }
};

// -------- Main Program --------
int main() {

    Stack s;
    int choice;

    do {
        cout << "\n1. Add Part\n2. Take Part\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            Inventory p;
            int sNum, year, lot;

            cout << "Enter Serial Number: ";
            cin >> sNum;
            cout << "Enter Manufacture Year: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;

            p.setData(sNum, year, lot);
            s.push(p);
        }

        else if (choice == 2) {
            s.pop();
        }

    } while (choice != 3);

    s.display();

    return 0;
}
