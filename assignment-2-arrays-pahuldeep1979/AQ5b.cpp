//1024030982

//Tri diagonal matrix
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int tri[3*n-2];
    cout << "Enter tri-diagonal elements (lower, main, upper):\n";
    for (int i = 0; i < 3*n-2; i++) cin >> tri[i];
    cout << "Tri-diagonal matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << tri[n-1 + i] << " ";
            else if (i == j+1) cout << tri[j] << " ";
            else if (i+1 == j) cout << tri[2*n-1 + i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}

// n = 4
//Lower diagonal: tri[0] to tri[2] (for positions (1,0), (2,1), (3,2))
//Main diagonal: tri[3] to tri[6] (for positions (0,0), (1,1), (2,2), (3,3))
//Upper diagonal: tri[7] to tri[9] (for positions (0,1), (1,2), (2,3))