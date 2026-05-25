#include <bits/stdc++.h>
using namespace std;

int r;
int c;

int solve(vector<vector<int>> &v)
{
    queue<pair<int, int>> q;
    int cnt = 0;    // Đếm các vị trí cần gieo
    int cnt2 = 0;   // Đếm các vị trí đã có cây

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] == 2)
            {
                cnt2++;
                q.push({i, j});
            }

            if (v[i][j] != 0)
            {
                cnt++;
            }
        }
    }

    if (cnt2 == cnt)
    {
        return 0;
    }

    int dem = 0;
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {1, -1, 0, 0};

    while (!q.empty())
    {
        int sz = q.size();

        if (cnt == cnt2)
        {
            return dem;
        }

        for (int i = 0; i < sz; i++)
        {
            int pos_i = q.front().first;
            int pos_j = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int next_i = pos_i + di[j];
                int next_j = pos_j + dj[j];

                if (next_i >= 0 && next_i < r && next_j >= 0 && next_j < c && v[next_i][next_j] == 1)
                {
                    q.push({next_i, next_j});
                    v[next_i][next_j] = 2;
                    cnt2++;
                }
            }
        }

        dem++;
    }
    
    return -1;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> r >> c;
        vector<vector<int>> v(r, vector<int>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> v[i][j];
            }
        }

        cout << solve(v) << endl;
    }
}