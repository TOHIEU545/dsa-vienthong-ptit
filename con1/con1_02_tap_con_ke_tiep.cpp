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
        int arr[k];
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }

        int i = k - 1;
        while (i >= 0 && (arr[i] >= n - k + i + 1))
        {
            i--;
        }
        if (i < 0)
        {
            for (int j = 1; j <= k; j++)
            {
                cout << j << " ";
            }
        }
        else
        {
            arr[i]++;
            for (int j = i + 1; j < k; j++)
            {
                arr[j] = arr[j - 1] + 1;
            }
            for (int j = 0; j < k; j++)
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}