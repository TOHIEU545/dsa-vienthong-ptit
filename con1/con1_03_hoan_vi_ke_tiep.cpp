#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        /* Tìm i sao cho ai < ai+1 */
        int i = n - 2;
        while (i >= 0 && a[i] >=a[i + 1])
        {
            i--;
        }

        if (i < 0)
        {
            /* Hoán vị cuối cùng, in ra hóa vị tăng dần */
            for (int j = 0; j < n; j++)
            {
                cout << (j + 1) << " ";
            }
        }
        else
        {
            /* Tìm j sao cho a[j] > a[i] */
            int j = n - 1;
            while (a[j] <= a[i])
            {
                j--;
            }
            swap(a[i], a[j]);
            int left = i + 1;
            reverse(a + left, a + n);
            for (int j = 0; j < n; j++)
            {
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }
    
}