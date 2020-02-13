#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        LL n, g, b;
        scanf("%lld%lld%lld", &n, &g, &b);
        LL half = (n + 1) / 2, res = n - half;
        LL lg1 = half / g, lg2 = half % g;
        if(lg2 == 0)  --lg1, lg2 = g;
        LL ans = lg1 * (g + b) + lg2;
        if(res > lg1 * b){
            res -= lg1 * b;
            ans += res;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
