# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PII;
double cx, cy;
map<PII, bool> mp;
 
struct Point{
    LL x, y;
}p[MAXN];
 
 
void init(){
    cx = 0, cy = 0;
    mp.clear();
}
 
int main(){
    int n;
    scanf("%d", &n);
    init();
    for(int i = 1; i <= n; ++i){
        scanf("%lld%lld", &p[i].x, &p[i].y);
        cx += p[i].x;
        cy += p[i].y;
        mp[mk(p[i].x, p[i].y)] = true;
    }
    cx /= n;
    cy /= n;
    bool flag = true;
    LL sx, sy;
    for(int i = 1; i <= n; ++i){
        sx = LL(2.0 * cx - p[i].x);
        sy = LL(2.0 * cy - p[i].y);
        if(not mp[mk(sx, sy)]){
            flag = false;
            break;
        }
    }
    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}
/*
3
4
13 16 2 3 20 18 5 4
 */
