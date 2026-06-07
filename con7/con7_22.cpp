#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test; cin >> test;
    while (test--)
    {
        int n; cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> left(n, -1), right(n, -1);
        stack<int> st;
        
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && (arr[st.top()] >= arr[i]))
            {
                st.pop();
            }
            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }

        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && (arr[st.top()] >= arr[i]))
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = left[i], r = right[i];
            if (l == -1) l = -1;
            if (r == -1) r = n;
            int w = r - l - 1, h = arr[i];
            if ((w * h) >= ans) ans = (w * h); 
        }
        cout << ans << endl;
    }
}