#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int p[MAXN], r[MAXN], cnt[MAXN];
bool vis[MAXN];



void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(vis, false, sizeof(vis));
}

int main(){
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        init();
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= m; ++i){
            scanf("%d", &p[i]);
        }
        for(int i = 1; i <= q; ++i){
            scanf("%d", &r[i]);
            vis[r[i]] = true;
        }
        for(int i = 1; i <= m; ++i){
            int tp = int(sqrt(p[i]));
            for(int j = 1; j <= tp; ++j){
                if(p[i]%j == 0){
                    if(vis[j])  ++cnt[j];
                    if(j*j != p[i] && vis[p[i]/j])  ++cnt[p[i]/j];
                }
            }
        }
        LL ans = 0;
        for(int i = 1; i <= q; ++i){
            ans += n/r[i] - cnt[r[i]];
        }
        printf("Case #%d: %lld\n", cas, ans);
        ++cas;
    }
    return 0;
}


/*
3
11 1 2
8
2 3
11 11 11
1 2 3 4 5 6 7 8 9 10 11
1 2 3 4 5 6 7 8 9 10 11
1000 6 1
4 8 15 16 23 42
1
*/
