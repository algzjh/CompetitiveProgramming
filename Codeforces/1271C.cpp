#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct Node{
    int x, y;
}s, p[MAXN], newp, ansp;

int main(){
    int n;
    scanf("%d%d%d", &n, &s.x, &s.y);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    int cnt = 0, tcnt = 0;
    for(int i = 0; i < 4; ++i){
        newp.x = s.x + dx[i];
        newp.y = s.y + dy[i];
        tcnt = 0;
        for(int j = 1; j <= n; ++j){
            if(min(s.x, p[j].x) <= newp.x and newp.x <= max(s.x, p[j].x) and
               min(s.y, p[j].y) <= newp.y and newp.y <= max(s.y, p[j].y)){
                ++tcnt;
            }
        }
        if(cnt < tcnt){
            cnt = tcnt;
            ansp = newp;
        }
    }
    printf("%d\n", cnt);
    printf("%d %d\n", ansp.x, ansp.y);
    return 0;
}
