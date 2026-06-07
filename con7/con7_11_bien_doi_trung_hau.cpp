#include <bits/stdc++.h>
using namespace std;

// Function check toan tu
int check_pri_operator(char c)
{
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

bool check_operator_right(char c)
{
    if (c == '^') return true;
    else return false;
}

string solve(string &s)
{
    stack<char> st;
    string res = "";

    for (char c : s)
    {
        // Neu la toan hang
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'))
        {
            res.push_back(c);
        }
        // Neu la (
        else if (c == '(')
        {
            st.push('(');
        }
        // Neu la )
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res.push_back(st.top());
                st.pop();
            }

            // Lay ( ra khoi stack
            st.pop();
        }
        // Neu la toan tu
        else
        {
            while (!st.empty() && st.top() != '(')
            {
                if (check_pri_operator(st.top()) > check_pri_operator(c))
                {
                    res.push_back(st.top());
                    st.pop();
                }
                else if (check_pri_operator(st.top()) == check_pri_operator(c))
                {
                    if (!check_operator_right(c))
                    {
                        res.push_back(st.top());
                        st.pop();
                    }
                }
                else
                {
                    break;
                }
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
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