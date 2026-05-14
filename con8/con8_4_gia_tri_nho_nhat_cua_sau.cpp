#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        map<char, int> m;
        for (char c : s)
        {
            m[c]++;
        }
        priority_queue<int> pq;
        for (auto x : m)
        {
            pq.push(x.second);
        }
        while (k--)
        {
            int max = pq.top();
            pq.pop();
            max -= 1;
            pq.push(max);
        }
        long long res = 0;
        while (!pq.empty())
        {
            int num = pq.top();
            pq.pop();
            res += num * num;
        }
        cout << res << endl;
    }
}