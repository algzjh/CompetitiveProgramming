#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        if((n/2)&1){
            printf("NO\n");
        }else{
            printf("YES\n");
            int p = 2;
            for(int i = 1; i <= n/4; ++i){
                if(i != 1)  printf(" ");
                printf("%d", p);
                p += 2;
                printf(" %d", p);
                p += 4;
            }
            p = 1;
            for(int i = 1; i <= n/4; ++i){
                printf(" %d", p);
                p += 4;
                printf(" %d", p);
                p += 2;
            }
            printf("\n");
        }
    }
    return 0;
}
