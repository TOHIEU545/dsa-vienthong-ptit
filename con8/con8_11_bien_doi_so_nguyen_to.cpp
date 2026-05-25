#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;
bool is_prime[MAXN + 1];

void sang_snt(void)
{
    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (is_prime[i] == true)
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int solve(int s, int t)
{
    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({s, 0});

    while (!q.empty())
    {
        int x = q.front().first;
        int step = q.front().second;
        q.pop();

        if (x == t)
        {
            return step;
        }
        
        string str_temp = to_string(x);
        for (int i = 0; i < str_temp.length(); i++)
        {
            string str_temp_2 = str_temp;
            for (int j = 0; j < 10; j++)
            {
                str_temp_2[i] = (j + '0');
                int next = stoi(str_temp_2);
                if (is_prime[next])
                {
                    if (next >= 0 && next < INT_MAX && visited.count(next) == 0)
                    {
                        q.push({next, step + 1});
                        visited.insert(next);
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    sang_snt();

    int test;
    cin >> test;
    while (test--)
    {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
}