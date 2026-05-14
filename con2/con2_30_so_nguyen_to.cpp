#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 1000;
bool not_prime[LIMIT + 1];
vector<int> prime;

int n, p, s;
vector<int> current;
vector<vector<int>> result;

void sang(void)
{
    not_prime[0] = true;
    not_prime[1] = true;

    for (int i = 2; i * i <= LIMIT; i++)
    {
        if (not_prime[i] == false)
        {
            for (int j = i * i; j <= LIMIT; j += i)
            {
                not_prime[j] = true;
            }
        }
    }

    for (int i = 2; i <= LIMIT; i++)
    {
        if (not_prime[i] == false)
        {
            prime.push_back(i);
        }
    }
}

void Try(int start, int sum)
{
    if (sum > s) return;
    if (current.size() > n) return;
    if (sum == s)
    {
        if (current.size() == n)
        {
            result.push_back(current);
        }
        return;
    }

    for (int i = start; i < prime.size(); i++)
    {
        int value = prime[i];
        current.push_back(value);
        Try(i + 1, sum + value);
        current.pop_back();
    }
} 

int main()
{
    sang();

    int test;
    cin >> test;

    while(test--)
    {
        cin >> n >> p >> s;

        current.clear();
        result.clear();

        int start = upper_bound(prime.begin(), prime.end(), p) - prime.begin();

        Try(start, 0);

        cout << result.size() << endl;
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}