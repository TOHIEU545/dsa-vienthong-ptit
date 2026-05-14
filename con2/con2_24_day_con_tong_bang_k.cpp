#include <bits/stdc++.h>

using namespace std;

int n;
int sum;
int a[15];
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

void Try(int i, int cur_sum, vector<int> &v)
{
    if (cur_sum == sum)
    {
        show_kq(v);
        ok = true;
        cout << " ";
        return;
    }

    if (cur_sum > sum) return;
    if (i >= n) return;

    for (int j = i; j < n; j++)
    {
        v.push_back(a[j]);
        Try(j + 1, cur_sum + a[j], v);
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
        vector<int> v;
        ok = false;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        Try(0, 0, v);
        if (ok == false) cout << "-1";
        cout << endl;
    }
}