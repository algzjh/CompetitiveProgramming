# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];
int n, m, k;
 
 
int solve(int l, int r){
    int res = 0;
    int x, y;
    for(x = l; x <= l + m - k - 1; ++x){
        y = x - m + k - l + r + 1;
//        cout << "x: " << x << " y: " << y << endl;
        if(res == 0){
            res = max(a[x], a[y]);
        }else{
            res = min(res, max(a[x], a[y]));
        }
    }
    return res;
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        k = min(k, m - 1);
        int l, r;
        // r - l = n - 1 - k;
        // r = n - 1 - k + l <= n
        // l <= k + 1
        int ans = 0;
        for(l = 1; l <= k + 1; ++l){
            r = n - 1 - k + l;
//            cout << "l: " << l << " r: " << r << endl;
            ans = max(ans, solve(l, r));
        }
        printf("%d\n", ans);
    }
    return 0;
}
