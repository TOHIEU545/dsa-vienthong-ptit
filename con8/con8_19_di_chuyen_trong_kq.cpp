#include <bits/stdc++.h>

using namespace std;

int s;
int e;

struct node
{
    int z, x, y, step;
};

int solve(vector<vector<string>> &arr, int a, int b, int c, node start)
{
    queue<node> q;
    vector<vector<vector<int>>> visited(a, vector<vector<int>>(b, vector<int>(c, 0)));

    q.push(start);
    visited[start.z][start.x][start.y] = 1;

    int dz[6] = {1, -1, 0, 0, 0, 0};
    int dx[6] = {0, 0, 1, -1, 0, 0};
    int dy[6] = {0, 0, 0, 0, 1, -1};

    while (!q.empty())
    {
        node current = q.front();
        q.pop();

        if (arr[current.z][current.x][current.y] == 'E')
        {
            return current.step;
        }

        for (int i = 0; i < 6; i++)
        {
            int next_z = current.z + dz[i];
            int next_x = current.x + dx[i];
            int next_y = current.y + dy[i];

            if (next_z >= 0 && next_z < a &&
                next_x >= 0 && next_x < b &&
                next_y >= 0 && next_y < c &&
                visited[next_z][next_x][next_y] == 0 &&
                arr[next_z][next_x][next_y] != '#')
            {
                visited[next_z][next_x][next_y] = 1;
                q.push({next_z, next_x, next_y, current.step + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        vector<vector<string>> arr(a, vector<string>(b));
        node start;

        for (int z = 0; z < a; z++)
        {
            for (int x = 0; x < b; x++)
            {
                cin >> arr[z][x];
                for (int y = 0; y < c; y++)
                {
                    if (arr[z][x][y] == 'S')
                    {
                        start = {z, x, y, 0};
                    }
                }
            }
        }

        cout << solve(arr, a, b, c, start) << endl;
    }
}