#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        
        stack<char> st;
        string res;

        for (int i = 0; i <= s.size(); i++)
        {
            st.push(i + 1);
            if (i == s.size() || s[i] == 'I')
            {
                while (!st.empty())
                {
                    res += char(st.top() + '0');
                    st.pop();
                }
            }
        }
        cout << res << endl;
    }
}