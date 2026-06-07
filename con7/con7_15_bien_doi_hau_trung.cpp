#include <bits/stdc++.h>
using namespace std;

bool check_operator(char c)
{
    if (c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/' ||
        c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string solve(string s)
{
    stack<string> st;

    for (char c : s)
    {
        if (isalnum(c))
        {
            string tmp = "";
            tmp += c;
            st.push(tmp);
        }
        else if (check_operator(c))
        {
            string right = st.top();
            st.pop();

            string left = st.top();
            st.pop();

            string exp = "(" + left + c + right + ")";
            st.push(exp);
        }
    }
    return st.top();
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string p;
        cin >> p;
        cout << solve(p) << endl;
    }
}