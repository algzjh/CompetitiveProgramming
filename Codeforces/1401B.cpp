/*
 * Author: algzjh
 * Date: 22/8/2020
 * Comment: math, 900
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
int c[2][3];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 3; ++j){
                scanf("%d", &c[i][j]);
            }
        }
        int ans = 2*min(c[0][2], c[1][1]);
        if(c[0][1] > c[1][0]){
            ans -= 2*min(c[0][1] - c[1][0], c[1][2]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
*/
