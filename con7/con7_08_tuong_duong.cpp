#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    stack<int> st; // Luu dau moi truong
    int sign = 1;   // Luu dau hien tai
    st.push(1);

    string res = "";

    for (char c : s)
    {
        if (c == '-')
        {
            sign = -1;
        }
        else if (c == '+')
        {
            sign = +1;
        }
        else if (c == '(')
        {
            st.push(sign * st.top());
            sign = 1;
        }
        else if (c == ')')
        {
            st.pop();
        }
        else if (isalnum(c))
        {
            if (sign * st.top() == -1)
            {
                res.push_back('-');
            }
            else if (sign * st.top() == 1)
            {
                res.push_back('+');
            }
            res.push_back(c);
        }
    }
    if (res[0] == '+')
    {
        res.erase(0, 1);
    }
    return res;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}