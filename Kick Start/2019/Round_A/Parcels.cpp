/*
 * Kickstart 2019 - Round A
 * Parcels
 * tags: bfs, Manhattan distance, binary search answer
 */
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
const int MAXN = static_cast<const int>(300);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN][MAXN];
int R, C, dtime[MAXN][MAXN];
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};
bool vis[MAXN][MAXN];
queue<PII> q;

bool ok(int x, int y){
    return !(x < 1 || x > R || y < 1 || y > C || vis[x][y]);
}

void bfs(){
    while(!q.empty()){
        PII u = q.front();
        q.pop();
        int x = u.fi, y = u.se;
        vis[x][y] = true;
        int newx, newy;
        for(int i = 0; i < 4; ++i){
            newx = x + dirx[i];
            newy = y + diry[i];
            if(!ok(newx, newy)) continue;
            dtime[newx][newy] = dtime[x][y] + 1;
            q.push(mk(newx, newy));
            vis[newx][newy] = true;
        }
    }
}

bool check(int k){
    int max_xplusy = -INF, min_xplusy = INF;
    int max_xminusy = -INF, min_xminusy = INF;
    bool flag = false;
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            if(dtime[i][j] > k){
                max_xplusy = max(max_xplusy, i + j);
                min_xplusy = min(min_xplusy, i + j);
                max_xminusy = max(max_xminusy, i - j);
                min_xminusy = min(min_xminusy, i - j);
                flag = true;
            }
        }
    }
    if(!flag)  return true;
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            int now_maxd = 0;
            if(s[i][j] == '0'){
                now_maxd = max(now_maxd, abs(max_xplusy - (i + j)));
                now_maxd = max(now_maxd, abs(min_xplusy - (i + j)));
                now_maxd = max(now_maxd, abs(max_xminusy - (i - j)));
                now_maxd = max(now_maxd, abs(min_xminusy - (i - j)));
                if(now_maxd <= k)  return true;
            }
        }
    }
    return false;
}

void init(){
    memset(vis, false, sizeof(vis));
    memset(dtime, 0x3f, sizeof(dtime));
}

int main(){
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--){
        init();
        scanf("%d%d", &R, &C);
        for(int i = 1; i <= R; ++i){
            scanf("%s", s[i] + 1);
        }
        while(!q.empty())  q.pop();
        for(int i = 1; i <= R; ++i){
            for(int j = 1; j <= C; ++j){
                if(s[i][j] == '1'){
                    dtime[i][j] = 0;
                    vis[i][j] = true;
                    q.push(mk(i, j));
                }
            }
        }
        if(q.size() == R * C){
            printf("Case #%d: %d\n", cas++, 0);
            continue;
        }
        bfs();
        int Left = 0, Right = R + C, mid, ans = INF;
        while(Left <= Right){
            mid = (Left + Right) >> 1;
            if(check(mid)){
                ans = min(ans, mid);
                Right = mid - 1;
            }else{
                Left = mid + 1;
            }
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}

/*
the property of manhattan distance
by classified discussion
//x1  + y1 - x2 - y2
//-x1 + x2 - y1 + y2
complement
//x1 - y1 - x2 + y2
//-x1 + x2 + y1 - y2

//d( (x1, y1), (x2, y2) ) = max( abs( (x1 + y1) - (x2 + y2) ), abs( (x1 - y1) - (x2 - y2) ) )
*/
