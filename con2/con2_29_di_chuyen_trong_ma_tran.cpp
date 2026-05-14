#include <bits/stdc++.h>

using namespace std;

int m, n;
int a[105][105];
int dem;

void Try(int i, int j)
{
    if (i >= m || j >= n)
    {
        return;
    }

    if (i == m - 1 && j == n - 1)
    {
        dem++;
    }

    Try(i + 1, j);
    Try(i, j + 1);
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        dem = 0;
        Try(0, 0);
        cout << dem << endl;
    }
}