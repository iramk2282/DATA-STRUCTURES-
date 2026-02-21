#include <iostream>
#include <string>
using namespace std;

// ================= PROFILE CLASS =================
class Profile {
private:
    int id;
    string name;
    string gender;
    int age;
    string email;
    string interest;
    string dob;

public:
    // Constructor
    Profile(int i, string n, string g, int a, string e, string in, string d) {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
    }

    // Getter functions
    int getID() { return id; }
    string getName() { return name; }
    string getGender() { return gender; }
    int getAge() { return age; }
    string getEmail() { return email; }
    string getInterest() { return interest; }
    string getDOB() { return dob; }

    // Setter functions
    void setName(string n) { name = n; }
    void setGender(string g) { gender = g; }
    void setAge(int a) { age = a; }
    void setEmail(string e) { email = e; }
    void setInterest(string in) { interest = in; }
    void setDOB(string d) { dob = d; }

    // Display function
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << email << endl;
        cout << "Interest: " << interest << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "---------------------------\n";
    }
};

// ================= PORTAL CLASS (LINKED LIST) =================
class Portal {
private:
    struct Node {
        Profile profile;
        Node* next;

        Node(Profile p) : profile(p), next(NULL) {}
    };

    Node* head;

public:
    Portal() {
        head = NULL;
    }

    // 1?? Insert Profile
    void InsertProfile(int id, string name, string gender, int age,
                       string email, string interest, string dob) {

        Profile p(id, name, gender, age, email, interest, dob);
        Node* newNode = new Node(p);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        cout << "Profile Added Successfully!\n";
    }

    // 2?? Update Profile by ID
    void UpdateProfile(int id) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->profile.getID() == id) {

                string name, gender, email, interest, dob;
                int age;

                cout << "Enter New Name: ";
                cin >> name;
                cout << "Enter New Gender: ";
                cin >> gender;
                cout << "Enter New Age: ";
                cin >> age;
                cout << "Enter New Email: ";
                cin >> email;
                cout << "Enter New Interest: ";
                cin >> interest;
                cout << "Enter New DOB: ";
                cin >> dob;

                temp->profile.setName(name);
                temp->profile.setGender(gender);
                temp->profile.setAge(age);
                temp->profile.setEmail(email);
                temp->profile.setInterest(interest);
                temp->profile.setDOB(dob);

                cout << "Profile Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Profile not found!\n";
    }

    // 3?? Delete Profile by Name
    void DeleteProfile(string name) {
        if (head == NULL) {
            cout << "No profiles available.\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        if (temp->profile.getName() == name) {
            head = temp->next;
            delete temp;
            cout << "Profile Deleted Successfully!\n";
            return;
        }

        while (temp != NULL && temp->profile.getName() != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Profile not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Profile Deleted Successfully!\n";
    }

    // 4?? Search Profile
    void SearchProfile(string name) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->profile.getName() == name) {
                temp->profile.display();
                return;
            }
            temp = temp->next;
        }

        cout << "Profile not found!\n";
    }

    // 5?? Display All
    void Display() {
        if (head == NULL) {
            cout << "No profiles to display.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            temp->profile.display();
            temp = temp->next;
        }
    }
};

// ================= MAIN FUNCTION =================
int main() {
    Portal portal;
    int choice;

    do {
        cout << "\n===== SOCIAL MEDIA PORTAL =====\n";
        cout << "1. Add New Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Delete Profile\n";
        cout << "4. Search Profile\n";
        cout << "5. Display All Profiles\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, age;
        string name, gender, email, interest, dob;

        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Gender: ";
            cin >> gender;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Interest: ";
            cin >> interest;
            cout << "Enter DOB: ";
            cin >> dob;

            portal.InsertProfile(id, name, gender, age, email, interest, dob);
            break;

        case 2:
            cout << "Enter ID to update: ";
            cin >> id;
            portal.UpdateProfile(id);
            break;

        case 3:
            cout << "Enter Name to delete: ";
            cin >> name;
            portal.DeleteProfile(name);
            break;

        case 4:
            cout << "Enter Name to search: ";
            cin >> name;
            portal.SearchProfile(name);
            break;

        case 5:
            portal.Display();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
