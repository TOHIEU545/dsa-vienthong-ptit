#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string s)
{
    vector<int> coef(26, 0);

    stack<int> st;
    st.push(1);

    int sign = 1;

    for (char c : s)
    {
        if (c == '+')
        {
            sign = 1;
        }
        else if (c == '-')
        {
            sign = -1;
        }
        else if (c == '(')
        {
            // Vao nguoc moi
            // Dau trong ngoac bang ngoai ngoac * sign
            st.push(st.top() * sign);
            sign = 1; // Return vi da dung dau truoc ngoac roi;
        }
        else if (c == ')')
        {
            st.pop();
        }
        else
        {
            coef[c - 'a'] += st.top() * sign;
        }
    }
    return coef;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        vector<int> a = solve(str1), b = solve(str2);
        if (a == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}