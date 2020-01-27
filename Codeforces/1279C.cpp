# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN], b[MAXN], n, m, v2p[MAXN];
map<int, bool> markb, vis, bezero;
int bit[MAXN];

int lowbit(int x) {return x&(-x);}

int getSum(int i){
    int res = 0;
    while(i > 0){
        res += bit[i];
        i -= lowbit(i);
    }
    return res;
}

void add(int i, int val){
    while(i <= n){
        bit[i] += val;
        i += lowbit(i);
    }
}

void init(){
    markb.clear();
    vis.clear();
    bezero.clear();
    for(int i = 1; i <= n; ++i){
        bit[i] = 0;
    }
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%d%d", &n, &m);
        init();
        LL ans = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        reverse(a + 1, a + n + 1);
        for(int i = 1; i <= n; ++i){
            v2p[a[i]] = i;
            add(i, 1);
        }
        for(int i = 1; i <= m; ++i){
            scanf("%d", &b[i]);
            markb[b[i]] = true;
        }
        for(int i = 1; i <= m; ++i){
            if(not bezero[b[i]]){
                for(int j = v2p[b[i]] + 1; j <= n and (!vis[a[j]]); ++j){
                    if(markb[a[j]])  bezero[a[j]] = true;
                }
                ans += 2LL * (getSum(n) - getSum(v2p[b[i]])) + 1;

            }else{
                ans += 1LL;
            }
            add(v2p[b[i]], -1);
            vis[b[i]] = true;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
b_i
 */
