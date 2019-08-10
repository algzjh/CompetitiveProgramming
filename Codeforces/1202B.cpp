#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e6 + 5;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int d[10][10], cnt[10][10];
char s[MAXN];
 
int main(){
    scanf("%s", s+1);
    int n = strlen(s+1);
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i < n; ++i){
        ++cnt[int(s[i]-'0')][int(s[i+1]-'0')];
    }
    for(int x = 0; x <= 9; ++x){
        for(int y = 0; y <= 9; ++y){
            memset(d, 0x3f, sizeof(d));
            for(int u = 0; u <= 9; ++u){
                for(int cx = 0; cx <= 9; ++cx){
                    for(int cy = 0; cy <= 9; ++cy){
                        if(cx == 0 && cy == 0) continue;
                        int v = (u + x * cx + y * cy) % 10;
                        d[u][v] = min(d[u][v], cx + cy);
                    }
                }
            }
            int ans = 0;
            for(int i = 0; i <= 9; ++i){
                for(int j = 0; j <= 9; ++j){
                    if(cnt[i][j] == 0) continue;
                    if(d[i][j] == INF){
                        ans = -1;
                        break;
                    }
                    ans += (d[i][j] - 1) * cnt[i][j];
                }
                if(ans == -1)  break;
            }
            if(y != 0)  printf(" ");
            printf("%d", ans);
        }
        printf("\n");
    }
    return 0;
}
