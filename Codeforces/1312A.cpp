#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, m;
        scanf("%d%d", &n, &m);
        if(n%m == 0)  printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
