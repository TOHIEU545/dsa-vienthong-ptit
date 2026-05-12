#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        int a[k], old[k];
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
            old[i] = a[i];
        }
        int i = k - 1;
        while (i >= 0 && a[i] >= n - k + i + 1)
        {
            i--;
        }
        if (i < 0)
        {
            cout << k;
        }
        else
        {
            a[i] += 1;
            for (int j = i + 1; j < k; j++)
            {
                a[j] = a[j - 1] + 1;
            }

            int cnt = 0;

            for (int x : old)
            {
                bool ok = false;
                for (int y : a)
                {
                    if (x == y)
                    {
                        ok = true;
                        break;
                    }
                }
                if (ok == false)
                {
                    cnt++;
                }
            }

            cout << cnt;
        }
        cout << endl;
    }
}