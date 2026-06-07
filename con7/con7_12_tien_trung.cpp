#include <bits/stdc++.h>
using namespace std;

bool is_operator(char c)
{
    if (c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/' ||
        c == '^')
    {
        return true;
    }
    
    return false;
}

string solve(string s)
{
    stack<string> st;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (isalnum(c))
        {
            string tmp = "";
            tmp += c;
            st.push(tmp);
        }
        else if (is_operator(c))
        {
            string left = st.top();
            st.pop();
            string right = st.top();
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