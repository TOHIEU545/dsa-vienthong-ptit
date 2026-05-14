#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    queue<int> q;

    while (Q--)
    {
        string query;
        cin >> query;

        if (query == "PUSH")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (query == "POP")
        {
            if (!q.empty())
            {
                q.pop();
            }
        }
        else if (query == "PRINTFRONT")
        {
            if (q.empty())
            {
                cout << "NONE\n";
            }
            else
            {
                cout << q.front() << '\n';
            }
        }
    }

    return 0;
}