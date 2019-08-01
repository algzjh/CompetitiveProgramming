#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 3e5 + 5;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
vector<int> ans;
 
struct Edge{
    int u, v;
}e[MAXM];
 
 
void init(int n){
    for(int i = 1;i <= 3*n; ++i){
        vis[i] = false;
    }
    ans.clear();
}
 
int main(){
    int _;
    scanf("%d", &_);
    int n, m;
    while(_--){
        scanf("%d%d", &n, &m);
        init(n);
        for(int i = 1; i <= m; ++i){
            scanf("%d%d", &e[i].u, &e[i].v);
            if(!vis[e[i].u] && !vis[e[i].v]){
                ans.emplace_back(i);
                vis[e[i].u] = true;
                vis[e[i].v] = true;
            }
        }
        if(ans.size() >= n){
            printf("Matching\n");
            for(int i = 0; i < n; ++i){
                if(i != 0)  printf(" ");
                printf("%d", ans[i]);
            }
        }else{
            printf("IndSet\n");
            bool first = true;
            int cnt = 0;
            for(int i = 1; i <= 3*n; ++i){
                if(vis[i]) continue;
                if(!first) printf(" ");
                else first = false;
                printf("%d", i);
                ++cnt;
                if(cnt == n) break;
            }
        }
        printf("\n");
    }
    return 0;
}
