/*
 */
#include <bits/stdc++.h>
using namespace std;
string s;

int main()
{
    // freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_--)
    {
        int n;
        string d, s;
        cin >> n >> d >> s;
        int len = s.length();
        int pos = len;
        for (int i = 0; i < len; i++)
        {
            if (s[i] < d[0])
            {
                pos = i;
                break;
            }
        }
        s.insert(pos, d);
        cout << s << endl;
    }
    return 0;
}