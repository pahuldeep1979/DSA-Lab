//1024030982

#include <iostream>
using namespace std;

int main()
{
    char str[100];
    cin >> str;
    int l = 0;
    while (str[l] != '\0')
        l++;
    int i = 0;
    int j = l - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    cout << str;
    return 0;
}