#include <iostream>
#include <string>
using namespace std;

// ================= MOBILE CLASS =================
class Mobile {
private:
    string name;
    int unitsOnHand;
    double price;

public:
    // Constructor
    Mobile(string n, int u, double p) {
        name = n;
        unitsOnHand = u;
        price = p;
    }

    // Setter functions
    void setName(string n) {
        name = n;
    }

    void setUnits(int u) {
        unitsOnHand = u;
    }

    void setPrice(double p) {
        price = p;
    }

    // Getter functions
    string getName() {
        return name;
    }

    int getUnits() {
        return unitsOnHand;
    }

    double getPrice() {
        return price;
    }
};

// ================= STORE CLASS (LINKED LIST) =================
class Store {
private:
    // Node structure
    struct Node {
        Mobile mobile;
        Node* next;

        Node(Mobile m) : mobile(m), next(NULL) {}
    };

    Node* head;

public:
    Store() {
        head = NULL;
    }

    // Insert new mobile
    void insertMobile(string name, int units, double price) {
        Mobile m(name, units, price);
        Node* newNode = new Node(m);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Mobile inserted successfully!\n";
    }

    // Delete mobile by brand name
    void deleteMobile(string name) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // If first node is to be deleted
        if (temp->mobile.getName() == name) {
            head = temp->next;
            delete temp;
            cout << "Mobile deleted successfully!\n";
            return;
        }

        // Search in list
        while (temp != NULL && temp->mobile.getName() != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Mobile not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Mobile deleted successfully!\n";
    }

    // Display all mobiles
    void displayMobiles() {
        if (head == NULL) {
            cout << "No mobiles in store.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << "Brand: " << temp->mobile.getName() << endl;
            cout << "Units: " << temp->mobile.getUnits() << endl;
            cout << "Price: " << temp->mobile.getPrice() << endl;
            cout << "----------------------\n";
            temp = temp->next;
        }
    }
};

// ================= MAIN FUNCTION =================
int main() {
    Store store;
    int choice;
    string name;
    int units;
    double price;

    do {
        cout << "\n1. Insert Mobile\n";
        cout << "2. Delete Mobile\n";
        cout << "3. Display Mobiles\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Brand Name: ";
            cin >> name;
            cout << "Enter Units: ";
            cin >> units;
            cout << "Enter Price: ";
            cin >> price;
            store.insertMobile(name, units, price);
            break;

        case 2:
            cout << "Enter Brand Name to delete: ";
            cin >> name;
            store.deleteMobile(name);
            break;

        case 3:
            store.displayMobiles();
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
