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
char s[MAXN], ans[30];
int du[30], p;
vector<int> G[30];
map<PII, bool> mp;
bool flag1, flag2;
bool vis[30];

void init(){
    memset(ans, 0, sizeof(ans));
    mp.clear();
    for(int i = 0; i < 26; ++i){
        G[i].clear();
        du[i] = 0;
        vis[i] = false;
    }
    p = 1;
    flag1 = flag2 = true;
}


void dfs(int u, int fa){
    if(vis[u] or not flag2){
        flag2 = false;
        return;
    }
    vis[u] = true;
    ans[p++] = char('a' + u);
    for(int v : G[u]){
        if(v == fa) continue;
        dfs(v, u);
    }
}

int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        init();
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        if(n == 1){
            printf("YES\n");
            for(int i = 0; i < 26; ++i){
                printf("%c", char('a' + i));
            }
            printf("\n");
            continue;
        }
        int u, v;
        for(int i = 1; i < n; ++i){
            u = s[i] - 'a';
            v = s[i + 1] - 'a';
            if(u > v)  swap(u, v);
            if(not mp[mk(u, v)]){
                mp[mk(u, v)] = true;
                G[u].emplace_back(v);
                G[v].emplace_back(u);
                ++du[u];
                ++du[v];
                if(du[u] > 2 or du[v] > 2){
                    flag1 = false;
                    break;
                }
            }
        }
        if(not flag1){
            printf("NO\n");
            continue;
        }
        for(int i = 0; i < 26; ++i){
            if(du[i] <= 1 and not vis[i]){
                dfs(i, -1);
            }
        }
        for(int i = 0; i < 26; ++i){
            if(not vis[i]){
                flag2 = false;
                break;
            }
        }
        if(flag2){
            ans[p] = '\0';
            printf("YES\n");
            printf("%s\n", ans + 1);
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
/*
5
abcdcbaxyz
 */
