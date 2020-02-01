# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 500 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;


// 1-6, 2-5, 3-4, 21
int main(){
    // 14 * x + (1-6) = n
    int _;
    scanf("%d", &_);
    while(_--){
        LL n;
        scanf("%lld", &n);
        if(n >= 15 and n%14 >= 1 and n%14 <= 6)  printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/*
 */
