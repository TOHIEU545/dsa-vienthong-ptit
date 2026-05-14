#include <bits/stdc++.h>

using namespace std;

void show_kp(int num, int n)
{
    if (n < 1)
    {
        return;
    }
    show_kp(num >> 1, n - 1);
    if ((num & 1) == 0)
    {
        cout << "A";
    }
    else
    {
        cout << "B";
    }
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
            show_kp(i, n);
            cout << " ";
        }
        cout << endl;
    }
}