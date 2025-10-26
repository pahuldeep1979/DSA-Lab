// 1024030982

// Symmetric Matrix

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int sym[n * (n + 1) / 2];
    cout << "Enter elements for lower triangle (including diagonal):\n";
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> sym[k++];
    cout << "Symmetric matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                cout << sym[i * (i + 1) / 2 + j] << " ";
            else
                cout << sym[j * (j + 1) / 2 + i] << " ";
        }
        cout << endl;
    }
    return 0;
}