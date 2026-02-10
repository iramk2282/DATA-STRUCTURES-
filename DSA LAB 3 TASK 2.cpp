#include <iostream>
using namespace std;

int main()
{
    // Dynamically allocate memory for a single character
    char *ptr = new char;

    // Store a character in allocated memory
    cout << "Enter a character: ";
    cin >> *ptr;

    // Print the stored character
    cout << "Stored character is: " << *ptr << endl;

    // Deallocate memory
    delete ptr;

    // Set pointer to NULL (instead of nullptr)
    ptr = NULL;

    cout << "Memory deallocated successfully!" << endl;

    return 0;
}

