/*
 * Author: algzjh
 * Date: 27/8/2020
 * Comment: greedy, math, constructive algorithms, 1100
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;
const LL INF = 1e18;
const int MOD = 998244353;
LL c[2][3];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 3; ++j){
                scanf("%lld", &c[i][j]);
            }
        }
        LL ans = 0;
        LL m = min(c[0][2], c[1][1]);
        c[0][2] -= m;
        c[1][1] -= m;
        ans += 2 * m;

        m = min(c[0][1], c[1][0]);
        c[0][1] -= m;
        c[1][0] -= m;

        m = min(c[0][0], c[1][2]);
        c[0][0] -= m;
        c[1][2] -= m;

        ans -= 2 * min(c[0][1], c[1][2]);

        printf("%lld\n", ans);
    }
    return 0;
}
/*
3
2 3 2
3 3 1
4 0 1
2 3 0
0 0 1
0 0 1
*/
