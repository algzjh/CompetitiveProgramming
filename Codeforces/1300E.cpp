# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<double, int> PDI;
int a[MAXN], top;
PDI stk[MAXN];


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    top = 1;
    stk[top] = mk(1.0 * a[1], 1);
    double nowval;
    int nowlen;
    for(int i = 2; i <= n; ++i){
        nowval = 1.0 * a[i], nowlen = 1;
        while(top >= 1 and stk[top].fi > nowval){
            nowval = (nowval * nowlen + stk[top].fi * stk[top].se)
                    / (nowlen + stk[top].se);
            nowlen += stk[top].se;
            --top;
        }
        ++top;
        stk[top] = mk(nowval, nowlen);
    }
    for(int i = 1; i <= top; ++i){
        for(int j = 1; j <= stk[i].se; ++j){
            printf("%.10f\n", stk[i].fi);
        }
    }
    return 0;
}

/*
12
8 10 4 6 6 4 1 2 2 6 9 5

4.777777778
4.777777778
4.777777778
4.777777778
4.777777778
4.777777778
4.777777778
4.777777778
4.777777778
6.000000000
7.000000000
7.000000000
 */
