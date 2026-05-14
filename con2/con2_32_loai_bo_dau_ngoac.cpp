#include <bits/stdc++.h>

using namespace std;

bool Check(string s)
{
    if (s.empty() == true) return false;
    if (s.size() == 1 && isalpha(s[0]) == true) return false;

    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            cnt++;
        }
        else if (s[i] == ')')
        {
            cnt--;
        }

        if (cnt < 0) return false;
    }

    if (cnt == 0) return true;
    else return false;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;

        vector<string> ans;
        unordered_set<string> visted;
        queue<string> q;

        q.push(s);
        visted.insert(s);

        bool found = false;

        while (q.empty() == false)
        {
            string cur = q.front();
            q.pop();

            if (Check(cur))
            {
                ans.push_back(cur);
                found = true;
            }
            else
            {
                // Nếu chưa có chuỗi nào thì xét, có rồi bỏ qua
                if (found == false)
                {
                    for (int i = 0; i < cur.size(); i++)
                    {
                        if (cur[i] == '(' || cur[i] == ')')
                        {
                            string next = cur.substr(0, i) + cur.substr(i + 1);
                            
                            if (visted.find(next) == visted.end())
                            {
                                visted.insert(next);
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }
        if (found == false)
        {
            cout << -1;
        }
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}