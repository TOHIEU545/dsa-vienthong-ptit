#include <bits/stdc++.h>

int n;     // Số tờ tiến
int sum;   // Tổng số tiền
int b[35]; // Các mệnh giá tiền
int ans;   // Kỷ lục

using namespace std;

void Try(int i, long long cur, int cnt)
{
    if (cur > sum)
        return;
    if (cnt >= ans)
        return;

    if (cur == sum)
    {
        ans = min(ans, cnt);
        return;
    }

    for (int j = i; j <= n; j++)
    {
        Try(j + 1, cur + b[j], cnt + 1);
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> sum;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }

        sort(b + 1, b + n + 1, greater<long long>());

        ans = 1e9;

        Try(1, 0, 0);

        if (ans == 1e9)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}