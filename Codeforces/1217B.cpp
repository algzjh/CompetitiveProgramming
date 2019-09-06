#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e2 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
 
struct Node{
    int d, h;
}blow[MAXN];
 
int main(){
   int _;
   scanf("%d", &_);
   while(_--){
       int n, x;
       scanf("%d%d", &n, &x);
       int maxd = -INF, mindh = INF;
       for(int i = 1; i <= n; ++i){
           scanf("%d%d", &blow[i].d, &blow[i].h);
           maxd = max(maxd, blow[i].d);
           mindh = min(mindh, blow[i].h - blow[i].d);
       }
       if(x - maxd <= 0){
           printf("1\n");
       }else if(mindh >= 0){
           printf("-1\n");
       }else{
           printf("%d\n", int(ceil(1.0 * (maxd - x)/mindh)) + 1);
       }
   }
   return 0;
}
/*
3
4 10
4 1
3 2
2 6
1 100
 */
