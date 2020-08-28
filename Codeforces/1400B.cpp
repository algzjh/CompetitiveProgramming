/*
 * Author: algzjh
 * Date: 28/8/2020
 * Comment: greedy
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
        for(int i = 0; i <= min(p/s, cs); ++i){
            int tans = i, rp = p, rf = f;
            rp -= i * s;
            cs -= i;
            tans += i;

            rp -= min(rp/w, cw) * w;
            cw -= min(rp/w, cw);
            tans += min(rp/w, cw);


            if(s > w){
                tans += min(rf/w, cw);
                rf -= min(rf/w, cw) * w;
                cw -= min(rf/w, cw);

                tans += min(rf/s, cs);
                rf -= min(rf/s, cs) * s;
                cs -= min(rf/s, cs);
            }else{
                tans += min(rf/s, cs);
                rf -= min(rf/s, cs) * s;
                cs -= min(rf/s, cs);

                tans += min(rf/w, cw);
                rf -= min(rf/w, cw) * w;
                cs -= min(rf/w, cw);

            }
            ans = max(ans, tans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*

*/
