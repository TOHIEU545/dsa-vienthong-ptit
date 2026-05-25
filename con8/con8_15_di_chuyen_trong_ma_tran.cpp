#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &v, int m, int n)
{
    bool used[m][n];
    memset(used, false, sizeof(used));

    queue<pair<int, int>> q;
    q.push({0, 0});

    int cnt = 0;
    while (!q.empty())
    {
        queue<pair<int, int>> tmp = q;
        while (!tmp.empty())
        {
            int i = tmp.front().first;
            int j = tmp.front().second;
            tmp.pop();
            q.pop();

            if (i == m - 1 && j == n - 1)
            {
                return cnt;
            }

            int next_i = i + v[i][j];
            if (next_i < m && used[next_i][j] == false)
            {
                used[next_i][j] = true;
                q.push({next_i, j});
            }

            int next_j = j + v[i][j];
            if (next_j < n && used[i][next_j] == false)
            {
                used[i][next_j] = true;
                q.push({i, next_j});
            }
        }
        cnt++;
    }
    return -1;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> v(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        
        cout << solve(v, m, n) << endl;
    }
    
}