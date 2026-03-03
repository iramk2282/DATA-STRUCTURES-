#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

// Insert at beginning
void addBegin(int val) {
    Node* n = new Node{val, NULL, head};
    if (head) head->prev = n;
    head = n;
}

// Insert after specific value
void addAfter(int key, int val) {
    Node* t = head;
    while (t && t->data != key) t = t->next;
    if (!t) return;

    Node* n = new Node{val, t, t->next};
    if (t->next) t->next->prev = n;
    t->next = n;
}

// Delete at beginning
void delBegin() {
    if (!head) return;
    Node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete t;
}

// Delete after specific value
void delAfter(int key) {
    Node* t = head;
    while (t && t->data != key) t = t->next;
    if (!t || !t->next) return;

    Node* d = t->next;
    t->next = d->next;
    if (d->next) d->next->prev = t;
    delete d;
}

// Display
void show() {
    for (Node* t = head; t; t = t->next)
        cout << t->data << " <-> ";
    cout << "NULL\n";
}

int main() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    while (n--) {
        cin >> x;
        addBegin(x);
    }

    show();

    addAfter(45, 100);   // example insert after 45
    delAfter(45);        // example delete after 45
    delBegin();          // delete beginning

    show();
    return 0;
}
