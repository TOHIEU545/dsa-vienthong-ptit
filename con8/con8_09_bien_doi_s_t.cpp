#include <bits/stdc++.h>

using namespace std;

int solve(int s, int t)
{
    // Lưu đỉnh hiện tại và số bước
    queue<pair<int, int>> q;
    vector<bool> visited(20001, false);

    q.push({s, 0});
    visited[s] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int step = q.front().second;
        q.pop();

        if(x == t)
        {
            return step;
        }

        int next1 = x - 1;
        if (next1 >= 0 && visited[next1] == false)
        {
            visited[next1] = true;
            q.push({next1, step + 1});
        }

        int next2 = x * 2;
        if (next2 < 20000 && visited[next2] == false)
        {
            visited[next2] = true;
            q.push({next2, step + 1});
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
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
}