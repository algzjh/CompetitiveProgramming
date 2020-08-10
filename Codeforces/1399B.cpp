/*
 * Author: algzjh
 * Date: 10/8/20
 * Comment:
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 50 + 5;
const int MAXM = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[MAXN], b[MAXN];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        int mia = INF, mib = INF;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            mia = min(mia, a[i]);
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
            mib = min(mib, b[i]);
        }
        LL ans = 0;
        for(int i = 1; i <= n; ++i){
            ans += max(a[i] - mia, b[i] - mib);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
