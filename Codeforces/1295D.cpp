# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
 
 
LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a%b);
}
 
 
LL euler_phi(LL n) {
    LL m = LL(sqrt(n + 0.5));
    LL ans = n;
    for (LL i = 2; i <= m; i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        LL a, m;
        scanf("%lld%lld", &a, &m);
        LL g = gcd(a, m);
        printf("%lld\n", euler_phi(m/g));
    }
    return 0;
}
