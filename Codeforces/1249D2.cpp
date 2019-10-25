#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
vector<PII> v[MAXN];
set<PII> s;
vector<int> ans;
 
void init(){
    for(int i = 1; i <= 2e5; ++i) v[i].clear();
    s.clear();
    ans.clear();
}
 
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int L, R;
    int mi = INF, ma = -INF;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &L, &R);
        mi = min(mi, L);
        ma = max(ma, R);
        v[L].emplace_back(mk(R, i));
    }
    for(int i = mi; i <= ma; ++i){
        while(!s.empty() and s.begin()->first < i)  s.erase(s.begin());
        for(auto it : v[i])  s.insert(it);
        while(s.size() > k){
            ans.emplace_back((--s.end())->second);
            s.erase(--s.end());
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for(int i = 0; i < sz; ++i){
        if(i != 0)  printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
