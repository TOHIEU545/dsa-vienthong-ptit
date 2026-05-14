#include <bits/stdc++.h>

using namespace std;

void in_kq(vector<int> &v)
{
    cout << "(";
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0) cout << " ";
        cout << v[i];
    }

    cout << ") ";
}

void Try(int max_val, int sum_cur, vector<int> &v)
{
    if (sum_cur == 0)
    {
        in_kq(v);
        return;
    }

    for (int j = min(max_val, sum_cur); j >= 1; j--)
    {
        v.push_back(j);
        Try(j, sum_cur - j, v);
        v.pop_back();
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
        vector<int> v;

        Try(n, n, v);
        cout << endl;
    }
}