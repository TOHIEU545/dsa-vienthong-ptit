#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<pair<int, int>> pos;
    stack<int> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            pos.push_back({st.top(), i});
            st.pop();
        }
    }

    set<string> res;

    int sz = pos.size();

    for (int mask = 1; mask < (1 << sz); mask++)
    {
        vector<bool> remove(s.size(), false);

        for (int i = 0; i < sz; i++)
        {
            int ok = false;
            if (mask & (1 << i))
            {
                remove[pos[i].first] = true;
                remove[pos[i].second] = true;
            }
        }
        string tmp;
        for (int i = 0; i < s.size(); i++)
        {
            if (remove[i] == false)
            {
                tmp += s[i];
            }
        }
        res.insert(tmp);
    }
    for (auto &x : res)
    {
        cout << x << endl;
    }
}