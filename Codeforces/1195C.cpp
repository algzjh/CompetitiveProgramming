#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
LL h[2][MAXN];
LL ma[2][MAXN];
 
int main(){
    memset(ma, 0, sizeof(ma));
    LL n, ans;
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &h[0][i]);
        ma[0][i] = h[0][i];
    }
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &h[1][i]);
        ma[1][i] = h[1][i];
    }
    int op = 0;
    for(int i = 1; i <= n - 1; ++i){
                       ma[op^1][i + 1] = max(ma[op^1][i + 1], ma[op][i] + h[op^1][i + 1]);
        if(i + 2 <= n) ma[op^1][i + 2] = max(ma[op^1][i + 2], ma[op][i] + h[op^1][i + 2]);
 
        if(i + 2 <= n) ma[op^1][i + 2] = max(ma[op^1][i + 2], ma[op][i + 1] + h[op ^1][i + 2]);
        if(i + 3 <= n) ma[op^1][i + 3] = max(ma[op^1][i + 3], ma[op][i + 1] + h[op ^1][i + 3]);
 
        op ^= 1;
    }
    ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max(ans, ma[0][i]);
        ans = max(ans, ma[1][i]);
    }
    //ans = max(ma[0][n], ma[1][n]);
    for(int i = 1; i <= n; ++i){
        ma[0][i] = h[0][i];
        ma[1][i] = h[1][i];
    }
    op = 1;
    for(int i = 1; i <= n - 1; ++i){
                       ma[op^1][i + 1] = max(ma[op^1][i + 1], ma[op][i] + h[op^1][i + 1]);
        if(i + 2 <= n) ma[op^1][i + 2] = max(ma[op^1][i + 2], ma[op][i] + h[op^1][i + 2]);
 
        if(i + 2 <= n) ma[op^1][i + 2] = max(ma[op^1][i + 2], ma[op][i + 1] + h[op ^1][i + 2]);
        if(i + 3 <= n) ma[op^1][i + 3] = max(ma[op^1][i + 3], ma[op][i + 1] + h[op ^1][i + 3]);
 
        op ^= 1;
    }
    for(int i = 1; i <= n; ++i){
        ans = max(ans, ma[0][i]);
        ans = max(ans, ma[1][i]);
    }
    //ans = max(ans, ma[0][n]);
    //ans = max(ans, ma[1][n]);
    printf("%lld\n", ans);
    return 0;
}
