#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        LL x, y, a, b;
        scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        b = min(2 * a, b);
        if(x > y)  swap(x, y);
        printf("%lld\n", x * b + (y - x) * a);
    }
    return 0;
}
