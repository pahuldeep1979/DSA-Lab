// 1024030982

//  Upper triangular Matrix.

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int upper[n * (n + 1) / 2];
    cout << "Enter upper triangular elements row-wise:\n";
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            cin >> upper[k++];
    cout << "Upper triangular matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
                cout << upper[i * n - i * (i - 1) / 2 + (j - i)] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}