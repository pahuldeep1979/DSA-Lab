// 1024030982

// Write a program to count the total number of distinct elements in an array of length n

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Simple selection sort
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) // i nu shota knna..
                minIdx = j;
        // Swap
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    int distinct = 1; // At least one element
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            distinct++;
    }

    cout << "Total number of distinct elements: " << distinct << endl;
    return 0;
}