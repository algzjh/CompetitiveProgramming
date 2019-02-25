/*
 * Codeforces Round 542
 * Two Cakes
 * gredy, thinking
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define first fi
#define second se
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN], pos[MAXN][2];

int main() {
    int n;
    while(~scanf("%d", &n)){
        int x;
        for(int i = 1; i <= 2*n; ++i){
            scanf("%d", &x);
            if(pos[x][0] == 0)  pos[x][0] = i;
            else  pos[x][1] = i;
        }
        LL ans = pos[1][0] - 1 + pos[1][1] - 1, d1, d2;
        for(int i = 1; i < n; ++i){
            d1 = abs(pos[i + 1][0] - pos[i][0]) + abs(pos[i + 1][1] - pos[i][1]);
            d2 = abs(pos[i + 1][0] - pos[i][1]) + abs(pos[i + 1][1] - pos[i][0]);
            ans += min(d1, d2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
5
5 2 1 2 3 5 4 3 1 4

37
*/
