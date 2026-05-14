#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n;
        cin >> n;
        while (n--)
        {
            int i;
            cin >> i;
            if (i == 1)
            {
                cout << q.size() << endl;
            }
            else if (i == 2)
            {
                if (q.empty()) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else if (i == 3)
            {
                int num;
                cin >> num;
                q.push(num);
            }
            else if (i == 4)
            {
                if (!q.empty())
                {
                    q.pop();
                }
            }
            else if (i == 5)
            {
                if (!q.empty())
                {
                    cout << q.front() << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
            else if (i == 6)
            {
                if (!q.empty())
                {
                    cout << q.back() << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }
}