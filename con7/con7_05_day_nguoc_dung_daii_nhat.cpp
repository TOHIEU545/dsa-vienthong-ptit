#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string str;
        cin >> str;

        stack<int> s;
        s.push(-1);

        int ans = 0;
        
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                s.push(i);
            }
            else
            {
                s.pop();
                if (s.empty())
                {
                    s.push(i);
                }
                else
                {
                    ans = max(ans, i - s.top());
                }
            }
        }
        cout << ans << endl;
    }
}