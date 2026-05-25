#include <bits/stdc++.h>
using namespace std;

array<int, 6> rotate_left(array<int, 6> a)
{
    array<int, 6> b = a;

    b[0] = a[3];
    b[1] = a[0];
    b[4] = a[1];
    b[3] = a[4];

    return b;
}

array<int, 6> rotate_right(array<int, 6> a)
{
    array<int, 6> b = a;

    b[2] = a[1];
    b[5] = a[2];
    b[4] = a[5];
    b[1] = a[4];

    return b;
}

int solve(array<int, 6> src, array<int, 6> dst)
{
    queue<array<int, 6>> q;
    map<array<int, 6>, int> dist;

    q.push(src);
    dist[src] = 1;

    int cnt = 0;

    while (!q.empty())
    {
        // Lấy số lượng phần tử của tầng (layer) hiện tại
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            array<int, 6> cur = q.front();
            q.pop();

            if (cur == dst)
            {
                return cnt;
            }

            array<int, 6> next1 = rotate_left(cur);
            if (dist.count(next1) == 0)
            {
                q.push(next1);
                dist[next1] = 1;
            }

            array<int, 6> next2 = rotate_right(cur);
            if (dist.count(next2) == 0)
            {
                q.push(next2);
                dist[next2] = 1;
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
        array<int, 6> src, dst;

        for (int i = 0; i < 6; i++)
        {
            cin >> src[i];
        }

        for (int i = 0; i < 6; i++)
        {
            cin >> dst[i];
        }

        cout << solve(src, dst) << endl;
    }

    return 0;
}