#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 998244353;
const LL INF = 1e18;
int n, ans[MAXN];
LL bit[MAXN], s[MAXN];

int lowbit(int x)  {return x&(-x);}

void add(int x, int v){
    while(x <= n){
        bit[x] += v;
        x += lowbit(x);
    }
}

int solve(LL presum){
    /*
     * binary lifting
     * pos + 2^i <= target position <= pos + 2(i+1)
     * 1<<21 = 2097152
     * https://codeforces.com/blog/entry/61364
     */
    int pos = 0;
    LL nowsum = 0;
    for(int i = 21; i >= 0; --i){
        if((pos + (1<<i) <= n) and (nowsum + bit[pos + (1<<i)] <= presum)){
            pos += (1<<i);
            nowsum += bit[pos];
        }
    }
    return pos + 1;
}

void init(){
    memset(bit, 0, sizeof(bit));
}

int main(){
    init();
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &s[i]);
        add(i, i);
    }
    for(int i = n; i >= 1; --i){
        ans[i] = solve(s[i]);
        add(ans[i], -ans[i]);
    }
    for(int i = 1; i <= n; ++i){
        if(i != 1)  printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
/*

*/
