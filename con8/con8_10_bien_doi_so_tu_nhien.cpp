#include <bits/stdc++.h>

using namespace std;

int solve(int num)
{
    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({num, 0});
    visited.insert(num);

    while (!q.empty())
    {
        int x = q.front().first;
        int step = q.front().second;
        q.pop();

        if (x == 1)
        {
            return step;
        }

        int next1 = x - 1;
        if (next1 >= 1 && visited.count(next1) == 0)
        {
            visited.insert(next1);
            q.push({next1, step + 1});
        }

        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                int next2 = max(i, x / i);
                if (next2 >= 1 && visited.count(next2) == 0)
                {
                    visited.insert(next2);
                    q.push({next2, step + 1});
                }
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
        int num;
        cin >> num;
        cout << solve(num) << endl;
    }
}