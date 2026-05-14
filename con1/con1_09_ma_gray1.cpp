#include <bits/stdc++.h>

using namespace std;

void in_kq(int num, int n)
{
    if (n < 1) return;

    in_kq(num >> 1, n - 1);
    cout << (num & 1);
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < pow(2, n); i++)
        {
            int num = (i >> 1) ^ i;
            in_kq(num, n);
            cout << " ";
        }
        cout << endl;
    }
}