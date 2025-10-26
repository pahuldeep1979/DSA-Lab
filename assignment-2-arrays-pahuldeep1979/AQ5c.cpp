// 1024030982

//Lower triangular matrix

#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int lower[n*(n+1)/2];
    cout << "Enter lower triangular elements row-wise:\n";
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> lower[k++];
    cout << "Lower triangular matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << lower[i*(i+1)/2 + j] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}