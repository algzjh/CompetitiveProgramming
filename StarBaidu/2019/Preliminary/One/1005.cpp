#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

LL calc(LL n){
    LL op = (n-1)%6, m = (n-1)/(1LL*6), a1, d;
    if(op==0){
        a1 = 1;
        d = 4;
    }else if(op==1){
        a1 = 1;
        d = 3;
    }else if(op==2){
        a1 = 0;
        d = 1;
    }else if(op==3){
        a1 = 3;
        d = 6;
    }else if(op==4){
        a1 = 0;
        d = 1;
    }else if(op==5){
        a1 = 3;
        d = 3;
    }
    return a1 + m * d;
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        LL n;
        scanf("%I64d", &n);
        printf("%I64d\n", calc(n));
    }
    return 0;
}
