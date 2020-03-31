#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const int MOD = 998244353;


LL qpow(LL a, LL b){
    LL res = 1;
    while(b){
        if(b&1)  res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        LL ans = 2LL * 10 * 9 * qpow(10, n - i - 1) % MOD;
        ans = (ans + 10LL * 9 * 9 * (n - i + 1 - 2) % MOD * qpow(10, n - i - 2) % MOD) % MOD;
        printf("%lld ", ans);
    }
    printf("10\n");
    return 0;
}
/*
1
10

2
180 10
 */
