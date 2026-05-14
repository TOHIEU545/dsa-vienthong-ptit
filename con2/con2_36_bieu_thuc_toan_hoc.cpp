#include <bits/stdc++.h>

using namespace std;

int a[5];
int b[5];
bool used[5];
bool ok;

// Thử đặt dấu +, -, * giữa các số trong b
// pos: đang xét số b[pos]
// value: giá trị hiện tại tính từ trái sang phải
void TryOperator(int pos, int value)
{
    if (ok == true)
    {
        return;
    }

    if (pos == 5)
    {
        if (value == 23)
        {
            ok = true;
        }
        return;
    }

    // Thử đặt dấu +
    TryOperator(pos + 1, value + b[pos]);
    // Thử đặt dấu -
    TryOperator(pos + 1, value - b[pos]);
    // Thử đặt dấu *
    TryOperator(pos + 1, value * b[pos]);
}

void Try(int pos)
{
    if (ok == true)
    {
        return;
    }

    // Nếu đã chọn đủ 5 số thì bắt đầu thử dấu
    if (pos == 5)
    {
        TryOperator(1, b[0]);
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (used[i] == false)
        {
            used[i] = true;
            b[pos] = a[i];
            Try(pos + 1);
            used[i] = false;
        }
    }
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> a[i];
        }

        ok = false;
        memset(used, false, sizeof(used));

        Try(0);
        
        if (ok == false)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        cout << endl;
    }
}