#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e6+5;
typedef long long LL;

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        LL a, b, x, y, n;
        scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &n);
        if(a - x + b - y <= n){
            printf("%lld\n", x * y);
        }else{
            LL p1 = max(n + y - b, 0LL);
            LL p2 = min(a - x, n);
            LL ans = min(a * b - a * n + (a - b + n) * p1 - p1 * p1,
                         a * b - a * n + (a - b + n) * p2 - p2 * p2);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
