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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        stack<int> st;
        st.push(arr[n - 1]);

        int ans[n];
        ans[n - 1] = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty())
            {
                // Neu ptu ben phai nho hon hoac ban
                if (st.top() <= arr[i])
                {
                    st.pop(); // Loai
                }
                else if (st.top() > arr[i])
                {
                    // Lay va cap nhat
                    ans[i] = st.top();
                    st.push(arr[i]);
                    break;
                }
            }
            if (st.empty())
            {
                ans[i] = -1;
                st.push(arr[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}