#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        LL n, m;
        scanf("%lld%lld", &n, &m);
        LL ten_sum = 0;
        for(int i = 1; i <= 10; ++i){
            ten_sum += (1LL * i * m) % 10;
        }
        LL ans = n / (10 * m) * ten_sum;
        n = n % (10 * m);
        for(int i = 1; i <= 10; ++i){
            if(m * i > n) break;
            ans += (1LL * i * m) % 10;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
