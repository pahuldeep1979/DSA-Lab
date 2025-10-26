#include <iostream>
using namespace std;

int main() {
    int a[10][10], r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    cout << "Enter elements of matrix: ";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    cout << "Sum of each row: ";
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++)
            sum += a[i][j];
        cout << sum << " ";
    }

    cout << "\nSum of each column: ";
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += a[i][j];
        cout << sum << " ";
    }
    return 0;
}
