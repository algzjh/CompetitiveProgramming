#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int a, b;
        scanf("%d%d", &a, &b);
        int ans = 0;
        if(a == b){
            ans = 0;
        }else if(a > b){
            if((a - b)&1)  ans = 2;
            else ans = 1;
        }else if(a < b){
            if((b-a)&1)  ans = 1;
            else ans = 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
