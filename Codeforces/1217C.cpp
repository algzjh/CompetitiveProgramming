#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
char s[MAXN];
int rightzero[MAXN];
 
LL binary2decimal(int l, int r){
    LL ret = 0, now = 1;
    for(int i = r; i >= l; --i){
        if(s[i] == '1'){
            ret += now;
        }
        now *= 2;
    }
    return ret;
}
 
int main(){
   int _;
   scanf("%d", &_);
   while(_--){
       scanf("%s", s + 1);
       int len = strlen(s + 1);
       int p = 0;
       for(int i = 1; i <= len; ++i){
           if(s[i] == '1'){
               rightzero[i] = i - p - 1;
               p = i;
           }
       }
       int ans = 0;
       for(int i = 1; i <= len; ++i){
           if(s[i] == '1'){
               for(int j = i; j <= i + 17 && j <= len; ++j){
                   if(rightzero[i] >= binary2decimal(i, j) - (j - i + 1)) ++ans;
               }
           }
       }
       printf("%d\n", ans);
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
