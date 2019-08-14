#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 4e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const LL INF = 1e18;
LL a[MAXN];
int n;
 
LL gcd(LL a, LL b){
    return b==0?a:gcd(b, a%b);
}
 
int main(){
    scanf("%d", &n);
    for(int i = 1;i <= n; ++i){
        scanf("%lld", &a[i]);
    }
    LL g = a[1];
    for(int i = 2; i <= n; ++i){
        g = gcd(g, a[i]);
    }
    LL ans = 0;
    for(LL i = 1; i * i <= g; ++i){
        if(g % i == 0){
            ++ans;
            if(i * i != g) ++ans;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
