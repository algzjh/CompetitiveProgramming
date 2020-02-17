#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
 
 
struct Node{
    LL t, l, h;
}q[MAXN];
 
bool cmp(const Node &u, const Node &v){
    return u.t < v.t;
}
 
bool checkIntersect(LL l1, LL h1, LL l2, LL h2){
    return !(h1 < l2 or h2 < l1);
}
 
PLL getIntersect(LL l1, LL h1, LL l2, LL h2){
    return mk(max(l1, l2), min(h1, h2));
}
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        LL n, m;
        scanf("%lld%lld", &n, &m);
        q[0].t = 0, q[0].l = q[0].h = m;
        for(int i = 1; i <= n; ++i){
            scanf("%lld%lld%lld", &q[i].t, &q[i].l, &q[i].h);
        }
        sort(q, q + n + 1, cmp);
        bool flag = true;
        LL nowl = q[n].l, nowh = q[n].h, nowt = q[n].t;
        for(int i = n - 1; i >= 0; --i){
            LL delta_t = nowt - q[i].t;
            nowl -= delta_t;
            nowh += delta_t;
            if(checkIntersect(q[i].l, q[i].h, nowl, nowh)){
                PLL tmp = getIntersect(q[i].l, q[i].h, nowl, nowh);
                nowl = tmp.fi, nowh = tmp.se;
                nowt = q[i].t;
            }else{
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
