#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MOD = 998244353;
int dirx[4] = {-1,0,1,0};
int diry[4] = {0,1,0,-1};
 
struct Node{
    int x, y, f[4];
}p[MAXN];
 
 
bool isIntersect(PII r1, PII r2){
    return !(r1.se < r2.fi || r1.fi > r2.se);
}
 
PII getIntersect(PII r1, PII r2){
    PII newr = mk(max(r1.fi, r2.fi), min(r1.se, r2.se));
    return newr;
}
 
int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        PII rx = mk(-(1e5), 1e5);
        PII ry = mk(-(1e5), 1e5);
        int n;
        scanf("%d", &n);
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &p[i].x, &p[i].y);
            PII nowx = mk(p[i].x, p[i].x);
            PII nowy = mk(p[i].y, p[i].y);
            for(int j = 0; j < 4; ++j){
                scanf("%d", &p[i].f[j]);
                if(j == 0 && p[i].f[j] == 1){ // left
                    nowx.fi = -(1e5);
                }else if(j == 1 && p[i].f[j] == 1){// up
                    nowy.se = 1e5;
                }else if(j == 2 && p[i].f[j] == 1){// right
                    nowx.se = 1e5;
                }else if(j == 3 && p[i].f[j] == 1){// down
                    nowy.fi = -(1e5);
                }
            }
            if(!flag) continue;
            if(isIntersect(nowx, rx) && isIntersect(nowy, ry)){
                rx = getIntersect(nowx, rx);
                ry = getIntersect(nowy, ry);
            }else{
                flag = false;
            }
 
//            cout << rx.fi << " " << rx.se << endl;
//            cout << ry.fi << " " << ry.se << endl;
        }
        if(!flag)  printf("0\n");
        else{
            printf("1 %d %d\n", rx.fi, ry.fi);
        }
    }
    return 0;
}
