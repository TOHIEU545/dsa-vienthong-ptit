#include <bits/stdc++.h>

using namespace std;

int n;
int k;
int s;

int ans;

void Try(int start, int sum, int cnt)
{
    if (cnt == k)
    {
        if (sum == s)
        {
            ans++;
        }
        return;
    }

    if (sum > s) return;
    if (start > n) return;

    for (int i = start; i <= n; i++)
    {
        Try(i + 1, sum + i, cnt + 1);
    }
}

int main()
{
    while (cin >> n >> k >> s)
    {
        if (n == 0 && k == 0 && s == 0)
        {
            break;
        }

        ans = 0;

        Try(1, 0, 0);

        cout << ans << '\n';
    }
}