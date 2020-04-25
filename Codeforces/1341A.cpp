#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, a, b, c, d;
        scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
        if(n * (a + b) < c -d or c + d < n * (a - b)){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    return 0;
}
