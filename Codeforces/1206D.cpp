#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int MAXN = 125;
const int MAXM = 5e3 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
LL a[100005];
// (1<<60) = 1152921504606846976
int cnt[MAXN], n, dist[MAXN][MAXN], G[MAXN][MAXN];

void init(int n){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j)  G[i][j] = dist[i][j] = 0;
            else G[i][j] = dist[i][j] = INF;
        }
    }
}

int floyd(){
    int res = INF;
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i < k; ++i){
            if(a[i]&a[k]){
                for(int j = i + 1; j < k; ++j){
                    if(a[j] & a[k]){
                        res = min(res, dist[i][j] + 2);
                    }
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return (res==INF)?-1:res;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", a + i);
        if(a[i] == 0)  {--n, --i;}
    }
    if(n == 0) {printf("-1\n");  return 0;}
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 60; ++j){
            if(a[i] & (1LL<<j))  ++cnt[j];
        }
    }
    for(int i = 0; i < 60; ++i){
        if(cnt[i] >= 3) {printf("3\n");  return 0;}
    }
    init(n);
    for(int i = 1;  i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(a[i] & a[j]){
                G[i][j] = G[j][i] = dist[i][j] = dist[j][i] = 1;
            }
        }
    }
    printf("%d\n", floyd());
    return 0;
}

/*
10
565299879350784 4508014854799360 0 0 0 4503635094929409 18014810826352646 306526525186934784 0 0

3 6 28 9
1
1 1
0 1 1
1 0 1 1

5 12 9 16 48
1
1 1
1 1 1
0 0 0 1
0 0 0 1 1

1 2 4 8
1
0 1
0 0 1
0 0 0 1
*/
