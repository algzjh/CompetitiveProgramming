#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
 
LL gcd(LL a, LL b){
    return b==0?a:gcd(b, a%b);
}
 
int main(){
    LL X;
    scanf("%lld", &X);
    LL up = LL(sqrt(X));
    LL ans = X;
    LL a = 1, b = X;
    for(LL i = 1; i <= up; ++i){
        if(X%i == 0 and gcd(i, X/i) == 1){
            if(ans > max(i, X/i)){
                ans = max(i, X/i);
                a = i, b = X/i;
            }
        }
    }
    printf("%lld %lld\n", a, b);
    return 0;
}
