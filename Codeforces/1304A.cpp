#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int x, y, a, b;
        scanf("%d%d%d%d", &x, &y, &a, &b);
        // a * t + b * t = y - x
        if( (y - x) % (a + b) != 0){
            printf("-1\n");
        }else{
            printf("%d\n", (y - x) / (a + b));
        }
    }
    return 0;
}
