#include <bits/stdc++.h>

using namespace std;

string to_bin(int num)
{
    string res;
    while (num)
    {
        if (num & 1)
        {
            res = res + "1";
        }
        else
        {
            res = res + "0";
        }

        num /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        cout << 1 << " ";
        for (int i = 2; i <= n; i++)
        {
            cout << to_bin(i) << " ";
        }
        cout << endl;
    }
}