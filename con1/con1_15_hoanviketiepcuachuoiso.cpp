#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int stt;
        cin >> stt;
        string str;
        cin >> str;
        int i = str.length() - 2;
        while (i >= 0 && str[i] >= str[i + 1])
        {
            i--;
        }
        if (i < 0)
        {
            cout << stt <<  " BIGGEST";
        }
        else
        {
            int j = str.length() - 1;
            while (str[i] >= str[j])
            {
                j--;
            }
            swap(str[i], str[j]);
            reverse(str.begin() + i + 1, str.end());
            cout << stt << " " << str;
        }
        cout << endl;
    }
}