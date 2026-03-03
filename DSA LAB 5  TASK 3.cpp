#include <iostream>
using namespace std;

struct Player {
    string name;
    int score;
    Player *prev, *next;
};

Player* head = NULL;

// Insert in sorted order (ascending score)
void addPlayer(string name, int score) {
    Player* n = new Player{name, score, NULL, NULL};

    if (!head || score < head->score) {
        n->next = head;
        if (head) head->prev = n;
        head = n;
        return;
    }

    Player* t = head;
    while (t->next && t->next->score <= score)
        t = t->next;

    n->next = t->next;
    if (t->next) t->next->prev = n;
    n->prev = t;
    t->next = n;
}

// Delete by name
void deletePlayer(string name) {
    Player* t = head;
    while (t && t->name != name)
        t = t->next;

    if (!t) {
        cout << "Player not found!\n";
        return;
    }

    if (t->prev) t->prev->next = t->next;
    else head = t->next;

    if (t->next) t->next->prev = t->prev;

    delete t;
    cout << "Player deleted!\n";
}

// Display whole list
void display() {
    Player* t = head;
    while (t) {
        cout << t->name << " - " << t->score << endl;
        t = t->next;
    }
}

// Lowest score player
void lowest() {
    if (head)
        cout << "Lowest Score: " << head->name << " - " << head->score << endl;
}

// Players with same score
void sameScore(int s) {
    Player* t = head;
    while (t) {
        if (t->score == s)
            cout << t->name << " - " << t->score << endl;
        t = t->next;
    }
}

// Display backward from a player
void backwardFrom(string name) {
    Player* t = head;
    while (t && t->name != name)
        t = t->next;

    if (!t) {
        cout << "Player not found!\n";
        return;
    }

    while (t) {
        cout << t->name << " - " << t->score << endl;
        t = t->prev;
    }
}

int main() {
    int choice, score;
    string name;

    do {
        cout << "\n1.Add Player\n2.Delete Player\n3.Display All\n";
        cout << "4.Lowest Score\n5.Same Score\n6.Backward From Player\n7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter score: ";
                cin >> score;
                addPlayer(name, score);
                break;

            case 2:
                cout << "Enter name to delete: ";
                cin >> name;
                deletePlayer(name);
                break;

            case 3:
                display();
                break;

            case 4:
                lowest();
                break;

            case 5:
                cout << "Enter score: ";
                cin >> score;
                sameScore(score);
                break;

            case 6:
                cout << "Enter player name: ";
                cin >> name;
                backwardFrom(name);
                break;
        }

    } while (choice != 7);

    return 0;
}
