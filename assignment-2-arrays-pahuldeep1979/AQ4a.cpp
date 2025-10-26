// 1024030982

// concat
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str1[100];
    char str2[100];

    cout << "Enter 1st string";
    cin >> str1;
    cout << "Enter 2nd string";
    cin >> str2;
    int i = 0, j = 0;
    while (str1[i] != '\0')
        i++;
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    cout << "concatenated string :" << str1 << endl;
    return 0;
}
