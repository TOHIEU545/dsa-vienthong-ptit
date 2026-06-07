#include <bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    stack<char> st;
    bool ok = false;

    for (char c : s)
    {
        if (c != ')')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            ok = false;
            while (!st.empty() && st.top() != '(')
            {
                char tmp = st.top();
                st.pop();
                if (tmp == '^' ||
                    tmp == '*' ||
                    tmp == '+' ||
                    tmp == '-')
                {
                    ok = true;
                }
            }
            st.pop();
            if (ok == false) return false;
        }
    }
    return true;
}
int main()
{
    int test;
    cin >> test;
    cin.ignore();
    while (test--)
    {
        string s;
        getline(cin, s);
        if (solve(s)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}