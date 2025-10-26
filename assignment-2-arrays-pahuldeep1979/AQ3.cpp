// 1024030982
// Missing number
#include <iostream>
#include <vector>
using namespace std;

int ls(const vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) return i + 1;
    }
    return n;
}



int bs(const vector<int>& arr, int n) {
    int low = 0, high = n - 2; // indices in arr (size n-1)
    while (low <= high) {

        
        int mid = (low + high) / 2 ;
        if (arr[mid] == mid + 1) low = mid + 1;
        else high = mid - 1;
    }


    return low + 1; // first mismatch position + 1
}






int main() {

    
    int n;
    cin >> n;
    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> arr[i];

    cout << "The missing number (linear): " << ls(arr, n) << "\n";
    cout << "The missing number (binary): " << bs(arr, n) << "\n";
    return 0;
}
