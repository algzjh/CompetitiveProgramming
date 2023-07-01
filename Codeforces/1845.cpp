#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        if (k == 1)
        {
            cout << "NO" << endl;
        }
        else if (k == 2)
        {
            if (x == 1 && n % 2 != 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
                if (x == 1)
                {
                    cout << n / 2 << endl;
                    for (int i = 1; i <= n / 2; i++)
                    {
                        if (i != 1)
                            cout << " ";
                        cout << "2";
                    }
                    cout << endl;
                }
                else
                {
                    cout << n << endl;
                    for (int i = 1; i <= n; i++)
                    {
                        if (i != 1)
                            cout << " ";
                        cout << "1";
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "YES" << endl;
            if (x == 1)
            {
                if (n % 2 == 0)
                {
                    cout << n / 2 << endl;
                    for (int i = 1; i <= n / 2; i++)
                    {
                        if (i != 1)
                            cout << " ";
                        cout << "2";
                    }
                    cout << endl;
                }
                else
                {
                    cout << n / 2 + 1 << endl;
                    cout << "3";
                    for (int i = 1; i <= (n - 3) / 2; i++)
                    {
                        if (i != 1)
                            cout << " ";
                        cout << "2";
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << n << endl;
                for (int i = 1; i <= n; i++)
                {
                    if (i != 1)
                        cout << " ";
                    cout << "1";
                }
                cout << endl;
            }
        }
    }
    return 0;
}