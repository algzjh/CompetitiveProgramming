# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
LL t;

struct Point{
    LL x, y;
}P0, a, b, St, Pre, newP;

vector<Point> vp;

void init(){
    vp.clear();
}

LL dist(const Point &p1, const Point &p2){
    LL dx = p1.x - p2.x;
    LL dy = p1.y - p2.y;
    return abs(dx) + abs(dy);
}

int main(){
    scanf("%lld%lld%lld%lld%lld%lld", &P0.x, &P0.y, &a.x, &a.y, &b.x, &b.y);
    scanf("%lld%lld%lld", &St.x, &St.y, &t);
    init();
    Pre = P0;
    if(dist(P0, St) <= t)  vp.emplace_back(P0);
    while(true){
        newP.x = a.x * Pre.x + b.x;
        newP.y = a.y * Pre.y + b.y;
        if(dist(newP, St) <= t)  vp.emplace_back(newP);
        if(newP.x > 2e16 + 5 || newP.y > 2e16 + 5) break;
        Pre = newP;
    }
    int sz = vp.size();
//    for(auto p : vp){
//        cout << p.x << " " << p.y << endl;
//    }
    LL tmpD;
    int ans = 0;
    for(int l = 0; l < sz; ++l){
        for(int r = l; r < sz; ++r){
            tmpD = dist(vp[l], vp[r]) + min(dist(St, vp[l]), dist(St, vp[r]));
            if(tmpD <= t){
                ans = max(ans, r - l + 1);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
*/
