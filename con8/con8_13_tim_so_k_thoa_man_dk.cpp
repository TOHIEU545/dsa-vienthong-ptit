#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    unordered_set<char> used;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > '5') return false;
        if (used.count(s[i]) == 0)
        {
            used.insert(s[i]);
        }
        else
        {
            return false;
        }
    }
    return true;
}

int solve(int l, int r)
{
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        string s = to_string(i);
        if (check(s))
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
}