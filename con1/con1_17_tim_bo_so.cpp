#include <bits/stdc++.h>

using namespace std;

long long kq(int n)
{
    queue<long long> q;
    q.push(9);

    while (!q.empty())
    {
        long long x = q.front();
        q.pop();

        if (x % n == 0)
        {
            return x;
        }
        else
        {
            q.push(x * 10);
            q.push(x * 10 + 9);
        }
    }

    return -1;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        cout << kq(n) << endl;
    }
}