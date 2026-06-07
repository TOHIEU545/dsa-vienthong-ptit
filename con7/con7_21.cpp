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
        for (int i = 0 ; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> nge(n, -1), nse(n, -1);
        stack<int> st;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && (arr[st.top()] <= arr[i]))
            {
                st.pop();
            }
            if (!st.empty())
            {
                nge[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && (arr[st.top()] >= arr[i]))
            {
                st.pop();
            }
            if (!st.empty())
            {
                nse[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++)
        {
            if (nge[i] == -1)
            {
                cout << -1 << " ";
            }
            else
            {
                int j = nge[i];
                if (nse[j] == -1)
                {
                    cout << -1 << " ";
                }
                else 
                {
                    cout << arr[nse[j]] << " ";
                }
            }
        }
        cout << endl;
    }
}