#include <bits/stdc++.h>
using namespace std;

string rotate_left(string a)
{
    string b = a;

    b[0] = a[3];
    b[1] = a[0];
    b[5] = a[1];
    b[8] = a[5];
    b[7] = a[8];
    b[3] = a[7];

    return b;
}

string rotate_right(string a)
{
    string b = a;

    b[1] = a[4];
    b[2] = a[1];
    b[6] = a[2];
    b[9] = a[6];
    b[8] = a[9];
    b[4] = a[8];

    return b;
}

string inv_left(string a)
{
    string b = a;

    b[3] = a[0];
    b[0] = a[1];
    b[1] = a[5];
    b[5] = a[8];
    b[8] = a[7];
    b[7] = a[3];

    return b;
}

string inv_right(string a)
{
    string b = a;

    b[4] = a[1];
    b[1] = a[2];
    b[2] = a[6];
    b[6] = a[9];
    b[9] = a[8];
    b[8] = a[4];

    return b;
}

int solve(string start)
{
    string target = "1238004765";

    if (target == start)
    {
        return 0;
    }

    queue<string> q1;
    unordered_map<string, int> d1;

    q1.push(start);
    d1[start] = 0;

    // BFS khong qua 14 lan xuoi de tim so buoc di
    while (!q1.empty())
    {
        string cur = q1.front();
        q1.pop();

        if (d1[cur] < 14)
        {
            string l = rotate_left(cur);
            string r = rotate_right(cur);

            if (!d1.count(l))
            {
                d1[l] = d1[cur] + 1;
                q1.push(l);
            }
            if (!d1.count(r))
            {
                d1[r] = d1[cur] + 1;
                q1.push(r);
            }
        }
    }

    queue<string> q2;
    unordered_map<string, int> d2;

    q2.push(target);
    d2[target] = 0;

    int ans = INT_MAX;

    while (!q2.empty())
    {
        string cur = q2.front();
        q2.pop();

        if (d1.count(cur))
        {
            ans = min(ans, d1[cur] + d2[cur]);
        }

        if (d2[cur] < 14)
        {
            string l = inv_left(cur);
            string r = inv_right(cur);

            if (!d2.count(l))
            {
                d2[l] = d2[cur] + 1;
                q2.push(l);
            }
            if (!d2.count(r))
            {
                d2[r] = d2[cur] + 1;
                q2.push(r);
            }
        }
    }

    return ans;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string str = "";
        char c;
        for (int i = 0; i < 10; i++)
        {
            cin >> c;
            str.push_back(c);
        }

        cout << solve(str) << endl;

    }
}