#include <bits/stdc++.h>

using namespace std;

int n, m;

// a[u][v] = 1 nghĩa là có cạnh nối u với v
int a[25][25];

// used[u][v] = true nghĩa là cạnh u-v đã được đi qua
int used[25][25];

int ans;

void Try(int u, int length)
{
    if (length > ans)
    {
        ans = length;
    }

    // Thử đi từ u sang mọi đỉnh v
    for (int v = 0; v < n; v++)
    {
        if (a[u][v] == 1 && used[u][v] == false)
        {
            used[u][v] = true;
            used[v][u] = true;

            Try(v, length + 1);

            used[u][v] = false;
            used[v][u] = false;
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;

        memset(a, 0, sizeof(a));
        memset(used, false, sizeof(used));

         for (int i = 0; i < m; i++)
         {
            int u, v;
            cin >> u >> v;

            a[u][v] = 1;
            a[v][u] = 1;
         }

         ans = 0;

        // Chọn 1 đỉnh để đi
        for (int i = 0; i < n; i++)
        {
            Try(i, 0);
        }

        cout << ans << endl;
    }
}