#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    // Step 1: Create pointer-to-pointer
    int **matrix = new int*[rows];

    // Step 2: Allocate memory for each row
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    // Step 3: Input elements
    cout << "\nEnter matrix elements:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Step 4: Display matrix
    cout << "\nMatrix is:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Step 5: Free memory (delete each row first)
    for(int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    // Step 6: Delete main pointer
    delete[] matrix;

    // Set pointer to NULL (instead of nullptr)
    matrix = NULL;

    cout << "\nMemory freed successfully!" << endl;

    return 0;
}

