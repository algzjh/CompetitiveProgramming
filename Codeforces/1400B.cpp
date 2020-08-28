/*
 * Author: algzjh
 * Date: 28/8/2020
 * Comment: greedy, math, 1700
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100 + 5;
const int MAXM = 1e6 + 5;
const LL INF = 1e18;
const int MOD = 998244353;
char ans[MAXN], s[MAXN];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int p, f, cs, cw, s, w;
        scanf("%d%d%d%d%d%d", &p, &f, &cs, &cw, &s, &w);
        int ans = 0;
        if(s > w){
            swap(s, w);
            swap(cs, cw);
        }
        for(int i = 0; i <= min(p/s, cs); ++i){
            int tans = 0, rp = p, rf = f, tcs = cs, tcw = cw, t;
            rp -= i * s;
            tcs -= i;
            tans += i;

            t = min(rp/w, tcw);
            rp -= t * w;
            tcw -= t;
            tans += t;

            t = min(rf/s, tcs);
            rf -= t * s;
            tcs -= t;
            tans += t;

            t = min(rf/w, tcw);
            rf -= t * w;
            tcw -= t;
            tans += t;

            ans = max(ans, tans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
