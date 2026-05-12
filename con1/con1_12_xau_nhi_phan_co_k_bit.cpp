#include <bits/stdc++.h>

using namespace std;

void show_kq(int num, int n)
{
    if (n < 1)
    {
        return;
    }
    show_kq(num >> 1, n - 1);
    cout << (num & 1);
}

bool check(int num, int k)
{
    int temp = 0;
    while (num > 0)
    {
        if (num & 1 != 0) temp++;
        num = num >> 1;
    }
    if (temp == k) return true;
    else return false;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < pow(2, n); i++)
        {
            if (check(i, k))
            {
                show_kq(i, n);
                cout << endl;
            }
        }
    }
}