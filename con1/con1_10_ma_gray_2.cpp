/* Ảo ma cần so lại*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string str;
        cin >> str;
        string res = "";
        if (str[0] == '1')
        {
            res.push_back('1');
        }
        else
        {
            res.push_back('0');
        }

        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] != str[i - 1])
            {
                res.push_back('1');
            }
            else
            {
                res.push_back('0');
            }
        }
        cout << res << endl;
    }
}