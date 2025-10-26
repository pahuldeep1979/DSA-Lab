// 1024030982

// Diagonal matrix
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int diag[n];
    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++)
        cin >> diag[i];
    cout << "Diagonal matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i == j)
            {
                cout << diag[i];
            }
        cout << endl;
    }
    return 0;
}

// Tri-diagonal Matrix:  int tri[3*n - 2]; // Store lower, main, and upper diagonals

// Lower Triangular Matrix:  int lower[n*(n+1)/2]; // Map (i, j) where i >= j to index

// Upper Triangular Matrix:  int upper[n*(n+1)/2]; // Map (i, j) where i <= j to index

// Symmetric Matrix: int sym[n*(n+1)/2]; // Store only one half