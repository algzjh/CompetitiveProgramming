#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 1e6+5;
const int MOD = 1e9+7;
typedef long long LL;
LL N, K, x1, Y1, C, D, E1, E2, F;
LL A[MAXN];
LL sum[MAXN];

void gendata(){
    A[1] = (x1 + Y1) % F;
    int x2, y2;
    for(int i = 2; i <= N; ++i){
        x2 = (C*x1 + D*Y1 + E1) % F;
        y2 = (D*x1 + C*Y1 + E2) % F;
        A[i] = (x2 + y2) % F;
        x1 = x2;
        Y1 = y2;
    }
}

LL Qpow(LL a, LL b){
    LL res = 1;
    while(b){
        if(b&1) res = (res*a)%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}


void init(){
    sum[1] = K;
    for(int i = 2; i <= N; ++i){
        LL q = i;
        LL f1 = (Qpow(q, K) - 1 + MOD) % MOD;
        LL f2 = Qpow( q - 1, MOD - 2);
        sum[i] = i * f1 % MOD * f2 % MOD;
        sum[i] = (sum[i-1] + sum[i]) % MOD;
    }
}



int main() {
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &N, &K, &x1, &Y1, &C, &D, &E1, &E2, &F);
        gendata();
        init();
        LL ans = 0;
        for(LL i = 1; i <= N; ++i){
            //printf(" %d", A[i]);
            ans = (ans + (N - i + 1) * A[i] % MOD * sum[i] % MOD)%MOD;
        }
        printf("Case #%d: %lld\n",cas++, ans);
    }
    return 0;
}
/*
2
2 3 1 2 1 2 1 1 9
10 10 10001 10002 10003 10004 10005 10006 89273

*/
