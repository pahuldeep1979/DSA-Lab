// 1024030982

// Addition

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

    int sum_row[200], sum_col[200], sum_val[200];
    int k = 0;
    // Add matching triplets
    for (int i = 0; i < t1; i++)
    {
        int found = 0;
        for (int j = 0; j < t2; j++)
        {
            if (row1[i] == row2[j] && col1[i] == col2[j])
            {
                sum_row[k] = row1[i];
                sum_col[k] = col1[i];
                sum_val[k] = val1[i] + val2[j];
                val2[j] = 0; // Mark as added
                found = 1;
                break;
            }
        }
        if (!found)
        {
            sum_row[k] = row1[i];
            sum_col[k] = col1[i];
            sum_val[k] = val1[i];
        }
        k++;
    }
    // Add remaining mat2 triplets
    for (int j = 0; j < t2; j++)
    {
        if (val2[j] != 0)
        {
            sum_row[k] = row2[j];
            sum_col[k] = col2[j];
            sum_val[k] = val2[j];
            k++;
        }
    }

    cout << "Sum triplets:\n";
    for (int i = 0; i < k; i++)
        cout << sum_row[i] << " " << sum_col[i] << " " << sum_val[i] << endl;

    return 0;
}