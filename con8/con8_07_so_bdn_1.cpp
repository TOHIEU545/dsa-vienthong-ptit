#include <bits/stdc++.h>
using namespace std;

vector <unsigned long long> bdn;

void Try(unsigned long long x)
{
    if (x > LLONG_MAX) return;

    bdn.push_back(x);

    if (x < LLONG_MAX / 10)
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
        int n;
        cin >> n;
        cout << (upper_bound(bdn.begin(), bdn.end(), n) - bdn.begin()) << endl;
    }
}