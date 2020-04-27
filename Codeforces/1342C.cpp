#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 4e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int ma[MAXN], mb[MAXN], dif[MAXN];
 
 
LL calc(LL n, int a, int b){
    LL t1 = n/(a*b), t2 = n%(a*b);
    return t1 * dif[a*b - 1] + dif[t2];
}
 
 
void init(int a, int b){
    for(int i = 0; i < a * b; ++i){
        ma[i] = (i%a)%b;
        mb[i] = (i%b)%a;
        dif[i] = (ma[i] != mb[i]);
        if(i >= 1){
            dif[i] += dif[i-1];
        }
    }
}
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int a, b, q;
        scanf("%d%d%d", &a, &b, &q);
        init(a, b);
        LL l, r;
        while(q--){
            scanf("%lld%lld", &l, &r);
            printf("%lld", calc(r, a, b) - calc(l - 1, a, b));
            printf("%c", q == 0 ? '\n' : ' ');
        }
    }
    return 0;
}
/*
2
4 6 2
1 7
1 9
7 10 1
100 200
*/
