// 1024030982
//  Binary search algorithm

#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
        int key;
        cout << "Enter the number of elements in the sorted array: ";
        cin >> n;
        int arr[100];
        cout << "Enter " << n << " sorted elements: ";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Enter the element to search: ";
        cin >> key;
        int left = 0, right = n - 1, found = 0, pos = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == key) {
                found = 1;
                pos = mid;
                break;
            } else if(arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if(found) {
            cout << "Element found at index: " << pos << endl;
        } else {
            cout << "Element not found in the array." << endl;
        }
        return 0;
}