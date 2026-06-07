#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string word;
        bool first = true;

        while (ss >> word)
        {
            reverse(word.begin(), word.end());

            cout << word << ' ';
        }
        cout << endl;
    }
}