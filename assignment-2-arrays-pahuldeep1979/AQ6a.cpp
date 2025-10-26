// 1024030982

// Transpose using sparse matrix

#include <iostream>
using namespace std;

int main()
{
    int m, n, t;
    cout << "Enter rows, columns, number of non-zero elements: ";
    cin >> m >> n >> t;
    int row[100], col[100], val[100];
    int t_row[100], t_col[100], t_val[100];

    cout << "Enter triplets (row col value):\n";
    for (int i = 0; i < t; i++)
        cin >> row[i] >> col[i] >> val[i];

    // Transpose: swap row and col
    for (int i = 0; i < t; i++)
    {
        t_row[i] = col[i];
        t_col[i] = row[i];
        t_val[i] = val[i];
    }

    cout << "Transpose triplets:\n";
    for (int i = 0; i < t; i++)
        cout << t_row[i] << " " << t_col[i] << " " << t_val[i] << endl;

    return 0;
}