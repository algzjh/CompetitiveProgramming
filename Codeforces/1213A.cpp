#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e3 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const LL INF = 1e18;
int x[MAXN];
 
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x[i]);
    }
    sort(x + 1, x + n + 1);
    LL ans = INF, tmp;
    for(int i = 1; i <= n; ++i){
        tmp = 0;
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            if(abs(x[i] - x[j]) & 1)  ++tmp;
        }
        ans = min(ans, tmp);
    }
    printf("%lld\n", ans);
    return 0;
}
