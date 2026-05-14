#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> bdn;

void Try(unsigned long long x)
{
    if (x > LLONG_MAX)
    {
        return;
    }

    bdn.push_back(x);

    if (x <= LLONG_MAX / 10)
    {
        Try(x * 10);
        Try(x * 10 + 1);
    }
}

int main()
{
    int test;
    cin >> test;
    Try(1);
    sort(bdn.begin(), bdn.end());

    while (test--)
    {
        int num;
        cin >> num;
        for (int i = 0 ; i < bdn.size(); i++)
        {
            if (bdn[i] % num == 0)
            {
                cout << bdn[i] << endl;
                break;
            }
        }
    }
}