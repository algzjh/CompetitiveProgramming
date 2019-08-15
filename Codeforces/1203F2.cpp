#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 105;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const LL INF = 1e18;
int dp[105][60005];
 
struct Node{
    int a, b;
}p[MAXN];
 
bool cmp(const Node& u, const Node& v){
    if(u.b >= 0 && v.b >= 0){
        return u.a < v.a;
    }else if(u.b < 0 && v.b < 0){
        return max(u.a, -u.b) + u.b > max(v.a, -v.b) + v.b;
    }else{
        return u.b > v.b;
    }
}
 
struct Node2{
    int w, v, rw;
}k[MAXN];
 
void init(){
    memset(dp, 0, sizeof(dp));
}
 
int main(){
    init();
    int n, r;
    scanf("%d%d", &n, &r);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &p[i].a, &p[i].b);
    }
    sort(p + 1, p + n + 1, cmp);
    int pre = 0, cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(p[i].b < 0){
            ++cnt;
            if(p[i].a <= abs(p[i].b)){
                k[cnt].w = abs(p[i].b);
                k[cnt].v = 1;
                k[cnt].rw = abs(p[i].b);
            }else{ // w > rw  a > b
                k[cnt].w = p[i].a;
                k[cnt].v = 1;
                k[cnt].rw = abs(p[i].b);
            }
        }else if(p[i].b >= 0 && r >= p[i].a){
            r += p[i].b;
            ++pre;
        }
    }
    for(int i = 1; i <= cnt; ++i){
        for(int j = 0; j <= r; ++j){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j - k[i].w >= 0) dp[i][j - k[i].rw] = max(dp[i][j - k[i].rw], dp[i - 1][j] + k[i].v);
        }
    }
    int ma = 0;
    for(int i = 1; i <= cnt; ++i){
        for(int j = 0; j <= r; ++j){
//            cout << "i: " << i << " j: " << j << " dp: " << dp[i][j] << endl;
            ma = max(ma, dp[i][j]);
        }
    }
    printf("%d\n", pre + ma);
    return 0;
}
 
 
/*
20 1000
37 -298
112 -288
29 -298
27 -298
334 -295
723 -298
139 -286
375 -296
19 -296
319 -300
323 -295
44 -300
237 -296
100 -296
370 -300
285 -299
359 -300
71 -297
459 -299
745 -298
 
3
 
 
3 4
4 6
10 -2
8 -1
 
5 20
45 -6
34 -15
10 34
1 27
40 -45
 
3 2
300 -300
1 299
1 123
 
*/
