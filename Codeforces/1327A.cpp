#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
typedef unsigned long long LL;
typedef pair<int, int> PII;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, k;
        scanf("%d%d", &n, &k);
        if((n&1) != (k&1)){
            printf("NO\n");
        }else{
            if(n >= 1LL * k * k){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
/*
1 3 5 7 9 11 13 15
1 4 9 16 25 36 49 64
 */
