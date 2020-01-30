# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e4 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
 
 
int main(){
    int _;
    cin >> _;
    while(_--){
        int n;
        cin >> n;
        string ans(n/2, '1');
        if(n&1)  ans[0] = '7';
        cout << ans << endl;
    }
    return 0;
}
