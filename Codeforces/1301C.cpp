#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
LL n, m;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%lld%lld", &n, &m);
        LL z = n - m, g = m + 1;
        LL k = LL(floor(1.0 * z / g));
        LL ans = n * (n + 1) / 2 - k * (k + 1) / 2 * g - (k + 1) * (z%g);
        printf("%lld\n", ans);
    }
    return 0;
}
