// 1024030982

// Delete all vowels

#include <iostream>
using namespace std;

int main()
{
    char s[100], result[100];

    cin >> s;
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        // to lowercase
        if (c >= 'A' && c <= 'Z')
            c = c + 32;
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
        {
            result[j++] = s[i];
        }
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
    return 0;
}