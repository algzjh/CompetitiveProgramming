#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e2 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[MAXN][MAXN];
bool vis[MAXN];

int main() {
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        int n;
        scanf("%d", &n);
        int trace = 0, repeat_row = 0, repeat_col = 0;
        bool repeat = false;
        for(int i = 1; i <= n; ++i){
            memset(vis, false, sizeof(vis));
            repeat = false;
            for(int j = 1; j <= n; ++j){
                scanf("%d", &a[i][j]);
                if(i == j)  trace += a[i][j];
                if(vis[a[i][j]]){
                    repeat = true;
                }else{
                    vis[a[i][j]] = true;
                }
            }
            if(repeat)  ++repeat_row;
        }
        for(int j = 1; j <= n; ++j){
            memset(vis, false, sizeof(vis));
            repeat = false;
            for(int i = 1; i <= n; ++i){
                if(vis[a[i][j]]){
                    repeat = true;
                    break;
                }else{
                    vis[a[i][j]] = true;
                }
            }
            if(repeat)  ++repeat_col;
        }
        printf("Case #%d: %d %d %d\n", cas++, trace, repeat_row, repeat_col);
    }
}
