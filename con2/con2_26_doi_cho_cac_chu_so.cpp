#include <bits/stdc++.h>

using namespace std;

string ans;

void Try(string &s, int k, int pos)
{
    if (k == 0 || pos == s.size())
    {
        return;
    }

    // Tìm chữ số lớn nhất từ pos đến cuối
    char max_digit = s[pos];

    for (int i = pos + 1; i < s.size(); i++)
    {
        if (s[i] > max_digit)
        {
            max_digit = s[i];
        }
    }

    if (max_digit != s[pos])
    {
        k--;
    }

    // Thử đưa tất cả các số max về vị trí pos
    for (int i = s.size() - 1; i >= pos; i--)
    {
        if (s[i] == max_digit)
        {
            swap(s[pos], s[i]);

            if (s > ans)
            {
                ans = s;
            }

            Try(s, k, pos + 1);

            swap(s[pos], s[i]);
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int k;
        cin >> k;
        string str;
        cin >> str;

        ans = str;

        Try(str, k, 0);

        cout << ans << endl;
    }
}