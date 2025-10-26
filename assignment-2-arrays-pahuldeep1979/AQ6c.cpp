// 1024030982

// Multiplication of sparse matrix.

#include <iostream>
using namespace std;

int main()
{
    int t1, t2;
    cout << "Enter number of non-zero elements in matrix 1: ";
    cin >> t1;
    int row1[100], col1[100], val1[100];
    cout << "Enter triplets (row col value) for matrix 1:\n";
    for (int i = 0; i < t1; i++)
        cin >> row1[i] >> col1[i] >> val1[i];

    cout << "Enter number of non-zero elements in matrix 2: ";
    cin >> t2;
    int row2[100], col2[100], val2[100];
    cout << "Enter triplets (row col value) for matrix 2:\n";
    for (int i = 0; i < t2; i++)
        cin >> row2[i] >> col2[i] >> val2[i];

    int prod_row[200], prod_col[200], prod_val[200];
    int k = 0;
    // Multiply: for each mat1(i, j), find mat2(j, l)
    for (int i = 0; i < t1; i++)
    {
        for (int j = 0; j < t2; j++)
        {
            if (col1[i] == row2[j])
            {
                prod_row[k] = row1[i];
                prod_col[k] = col2[j];
                prod_val[k] = val1[i] * val2[j];
                k++;
            }
        }
    }

    cout << "Product triplets:\n";
    for (int i = 0; i < k; i++)
        cout << prod_row[i] << " " << prod_col[i] << " " << prod_val[i] << endl;

    return 0;
}