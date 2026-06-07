#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    string str;
    int num;
    stack<int> s;
    while (q--)
    {
        cin >> str;
        if (str == "PUSH")
        {
            cin >> num;
            s.push(num);
        }
        else if (str == "PRINT")
        {
            if(s.empty())
            {
                cout << "NONE" << endl;
            }
            else
            {
                cout << s.top() << endl;
            }
        }
        else if (str == "POP")
        {
            if (!s.empty())
            {
                s.pop();
            }
        }
    }
}