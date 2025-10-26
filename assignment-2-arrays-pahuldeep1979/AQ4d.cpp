// 1024030982

// sort strings
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of strings: " << endl;
    cin >> n;
    char arr[10][100];
    cout << "Enter strings:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Simple bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                char temp[100];
                // Swap arr[j] and arr[j+1]
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }

    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}