#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
char s[MAXN];


int dfs(int l, int r, int c){
    if(l == r) {
        return s[l] == 'a' + c ? 0 : 1;
    }
    int changeLeft = 0, changeRight = 0;
    for(int i = l; i <= (l + r) / 2; ++i) {
        if(s[i] != 'a' + c)  ++changeLeft;
    }
    for(int i = (l + r) / 2 + 1; i <= r; ++i) {
        if(s[i] != 'a' + c)  ++changeRight;
    }
    return min(changeLeft + dfs((l+r)/2 + 1, r, c + 1),
               changeRight + dfs(l, (l+r)/2, c + 1));
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        printf("%d\n", dfs(1, n, 0));
    }
    return 0;
}
/*

*/
