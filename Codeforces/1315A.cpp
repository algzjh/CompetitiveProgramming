#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
 
int getMaxArea(int x1, int y1, int x2, int y2){
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        int ans = 0;
        ans = max(ans, getMaxArea(0, 0, a - 1, y - 1));
        ans = max(ans, getMaxArea(0, y + 1, a - 1, b - 1));
        ans = max(ans, getMaxArea(0, 0, x - 1, b - 1));
        ans = max(ans, getMaxArea(x + 1, 0, a - 1, b - 1));
        printf("%d\n", ans);
    }
    return 0;
}
