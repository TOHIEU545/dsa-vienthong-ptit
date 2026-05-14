#include <bits/stdc++.h>

using namespace std;

int n;
int sum;
int a[22];
bool ok;

void show_kq(vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << "]";
}

void Try(int i, int sum_cur, vector<int> &v)
{
    if (sum_cur > sum) return;
    if (sum_cur == sum)
    {
        show_kq(v);
        ok = true;
        return;
    }
    if (i >= n) return;

    for (int j = i; j < n; j++)
    {
        v.push_back(a[j]);
        Try(j, sum_cur + a[j], v);
        v.pop_back();
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> sum;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        vector<int> v;
        ok = false;
        Try(0, 0, v);
        if (ok == false)
        {
            cout << -1;
        }
        cout << endl;
    }
}