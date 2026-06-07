#include <bits/stdc++.h>
using namespace std;

bool is_oper(char c)
{
    if (c == '^' ||
    c == '*' ||
    c == '/' ||
    c == '+' ||
    c == '-')
    {
        return true;
    }
    return false;
}

int check_pri_oper(char c)
{
    if ( c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string tien_sang_trung(string s)
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
        else if (is_oper(c))
        {
            string left = st.top();
            st.pop();
            string right = st.top();
            st.pop();

            string tmp2 = "(" + left + c + right + ")";
            st.push(tmp2);
        }
    }
    return st.top();
}

string trung_sang_hau(string s)
{
    stack<char> st;
    string res = "";
    for (char c : s)
    {
        if (isalnum(c))
        {
            res.push_back(c);
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && st.top() != '(')
            {
                if (check_pri_oper(st.top()) > check_pri_oper(c))
                {
                        res.push_back(st.top());
                        st.pop();
                }
                else if (check_pri_oper(st.top()) == check_pri_oper(c))
                {
                    if (c != '^')
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
    while (!st.empty() && st.top() != '(')
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
        string s;
        cin >> s;
        cout << trung_sang_hau(tien_sang_trung(s)) << endl;
    }
}