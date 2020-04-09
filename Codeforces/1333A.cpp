#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e2 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, m;
        scanf("%d%d", &n, &m);
        if((n * m)&1){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= m; ++j){
                    if((i + j)&1)  printf("W");
                    else printf("B");
                }
                printf("\n");
            }
        }else{
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= m; ++j){
                    if(i + j == 2)  printf("B");
                    else if((i + j)&1)  printf("B");
                    else printf("W");
                }
                printf("\n");
            }
        }
    }
}
