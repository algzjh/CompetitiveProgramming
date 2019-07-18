#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MOD = 998244353;
LL a[MAXN], pow10[20];
 
void init(){
    pow10[0] = 1;
    for(int i = 1; i <= 19; ++i){
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
}
 
 
int main() {
    init();
    LL n;
    scanf("%lld", &n);
    LL ans = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &a[i]);
        LL pos = 0, bit;
        while(a[i] > 0){
            bit = a[i] % 10;
            ans = ( ( ans + n * bit * pow10[pos*2] % MOD ) % MOD + n * bit * pow10[(pos + 1)*2 - 1] % MOD) % MOD;
            ++pos;
            a[i]/=10;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
