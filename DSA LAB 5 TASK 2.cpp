#include <iostream>
using namespace std;

struct Node {
    float rain;
    Node *prev, *next;
};

int main() {
    Node *head = NULL, *temp = NULL, *newNode;
    float total = 0, highest, lowest;
    int dayHigh = 1, dayLow = 1;

    cout << "Enter rainfall for 7 days:\n";

    // Create doubly linked list
    for (int i = 1; i <= 7; i++) {
        newNode = new Node();
        cout << "Day " << i << ": ";
        cin >> newNode->rain;

        newNode->prev = temp;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    // Calculate total, highest, lowest
    temp = head;
    highest = lowest = head->rain;
    int day = 1;

    while (temp != NULL) {
        total += temp->rain;

        if (temp->rain > highest) {
            highest = temp->rain;
            dayHigh = day;
        }

        if (temp->rain < lowest) {
            lowest = temp->rain;
            dayLow = day;
        }

        temp = temp->next;
        day++;
    }

    cout << "\nTotal rainfall: " << total;
    cout << "\nAverage rainfall: " << total / 7;
    cout << "\nHighest rainfall: Day " << dayHigh << " (" << highest << ")";
    cout << "\nLowest rainfall: Day " << dayLow << " (" << lowest << ")";

    // Rainfall after 5th node
    temp = head;
    for (int i = 1; i < 6 && temp != NULL; i++)
        temp = temp->next;

    if (temp != NULL)
        cout << "\nRainfall after 5th day: " << temp->rain;
    else
        cout << "\nNo day after 5th node.";

    return 0;
}
