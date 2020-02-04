# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
 
 
// 1 tie, 1 jacket, e coins
// 1 scarf, 1 vest, 1 jacket, f coins
int main(){
    int tie, scarf, vest, jacket, e, f, ans = 0;
    scanf("%d%d%d%d%d%d", &tie, &scarf, &vest, &jacket, &e, &f);
    if(e > f){
        ans = e * min(tie, jacket);
        jacket -= min(tie, jacket);
        if(jacket > 0)  ans += f * min(scarf, min(vest, jacket));
    }else{
        ans = f * min(scarf, min(vest, jacket));
        jacket -= min(scarf, min(vest, jacket));
        if(jacket > 0)  ans += e * min(tie, jacket);
    }
    printf("%d\n", ans);
    return 0;
}
