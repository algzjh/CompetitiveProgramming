# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAX = 2e6 + 2;
const int MAXN = 2e6 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<double, int> PDI;
int A[MAXN], invA[MAXN];


int qpow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1)  res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}


void init(){
    A[0] = 1;
    for(int i = 1;i <= MAX; ++i){
        A[i] = 1LL * A[i-1] * i % MOD;
    }
    invA[MAX] = qpow(A[MAX], MOD - 2);
    for(int i = MAX - 1; i >= 0; --i){
        invA[i] = (1LL * invA[i + 1] * (i + 1)) % MOD;
    }
}

int C(int n, int m){
    return 1LL * A[n] * invA[m] % MOD * invA[n-m] % MOD;
}

int f(int r, int c){
    return C(r + c, c);
}

int g(int r, int c){
    int res = 0;
    for(int i = 2; i <= r + 1; ++i){
        res = (1LL * res + 1LL * f(i, c)) % MOD;
    }
    return (1LL * res - r + MOD) % MOD;
}


int calc(int r1, int c1, int r2, int c2){
    int res = 0;
    res = (1LL * res + g(r2, c2)) % MOD;
    if(c1 > 1)  res = (1LL * res - g(r2, c1 - 1) + MOD) % MOD;
    if(r1 > 1)  res = (1LL * res - g(r1 - 1, c2) + MOD) % MOD;
    if(c1 > 1 and r1 > 1)  res = (1LL * res + g(r1 - 1, c1 - 1)) % MOD;
    return res;
}


int main(){
    init();
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    printf("%d\n", calc(r1, c1, r2, c2));
    return 0;
}
/*
2 5 9 14 20 27 35 44 54 65
5 14 28 48 75 110 154 208 273 350
9 28 62 117 200 319 483 702 987 1350
14 48 117 242 451 780 1274 1988 2988 4352
20 75 200 451 912 1703 2989 4990 7992 12359
27 110 319 780 1703 3418 6420 11424 19431 31806
35 154 483 1274 2989 6420 12854 24293 43740 75563
44 208 702 1988 4990 11424 24293 48602 92359 167940
54 273 987 2988 7992 19431 43740 92359 184736 352695
65 350 1350 4352 12359 31806 75563 167940 352695 705410
 */
