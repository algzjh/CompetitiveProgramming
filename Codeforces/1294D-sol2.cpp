# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 4e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int cnt[MAXN], q, x, y;
set<PII> vals;


void init(){
    for(int i = 0; i <= x; ++i){
        cnt[i] = 0;
    }
}

int main(){
    scanf("%d%d", &q, &x);
    init();
    for(int i = 0; i < x; ++i){
        vals.insert(mk(cnt[i], i));
    }
    while(q--){
        scanf("%d", &y);
        y %= x;
        vals.erase(mk(cnt[y], y));
        ++cnt[y];
        vals.insert(mk(cnt[y], y));
        printf("%d\n", vals.begin()->first * x + vals.begin()->second);
    }
    return 0;
}
