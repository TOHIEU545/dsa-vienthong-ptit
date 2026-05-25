#include <bits/stdc++.h>

using namespace std;

string s, e;

void solve(unordered_set<string> &my_set)
{
    queue<string> q;
    q.push(s);

    int count = 1;
    string u;
    char old_i;

    while (!q.empty())  // Xử lý đến khi nào hết sạch
    {
        count++;

        queue<string> tmp = q;
        while (!tmp.empty())    // Xử lý hết các trường hợp ở tầng hiện tại
        {
            u = tmp.front();
            tmp.pop();
            q.pop();

            for (int i = 0; i < u.size(); i++)
            {
                old_i = u[i];
                for (char j = 'A'; j <= 'Z'; j++)
                {
                    u[i] = j;
                    if (u == e)
                    {
                        cout << count << endl;
                        return;
                    }
                    if (my_set.find(u) != my_set.end())
                    {
                        q.push(u);
                        my_set.erase(u);    // Đã đưa vào queue rồi thì xóa, tránh xét lại
                    }
                }
                u[i] = old_i;
            }
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n >> s >> e;
        unordered_set<string> my_set;
        string x;

        while (n--)
        {
            cin >> x; 
            my_set.insert(x);
        }

        if (s == e)
        {
            cout << 1 << endl;
        }
        else
        {
            solve(my_set);
        }
    }
}