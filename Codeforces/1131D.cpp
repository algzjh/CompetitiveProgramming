/*
 * Codeforces Round 541
 * D Gourmet choice
 * bfs, dsu
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2005;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN][MAXN];
int n, m, fa[MAXN], du[MAXN], ans[MAXN];
vector<int> G[MAXN];
queue<int> q;


int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void init(){
    for(int i = 1; i <= n + m; ++i){
        fa[i] = i;
        G[i].clear();
        ans[i] = 0;
        du[i] = 0;
    }
    while(not q.empty())  q.pop();
}

void bfs(){
    while(not q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : G[u]){
            --du[v];
            if(du[v] == 0){
                q.push(v);
                ans[v] = ans[u] + 1;
            }
        }
    }
}

int main() {
    while(~scanf("%d%d",&n, &m)){
        init();
        for(int i = 1; i <= n; ++i){
            scanf("%s", s[i] + 1);
        }
        int fu, fv;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(s[i][j] == '='){
                    fu = Find(i);
                    fv = Find(n + j);
                    fa[fu] = fv;
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                fu = Find(i);
                fv = Find(n + j);
                if(s[i][j] == '<'){
                    G[fu].emplace_back(fv);
                    //cout << "fu: " << fu << " fv: " << fv << endl;
                    ++du[fv];
                }else if(s[i][j] == '>'){
                    G[fv].emplace_back(fu);
                    //cout << "fv: " << fv << " fu: " << fu << endl;
                    ++du[fu];
                }
            }
        }
        for(int i = 1; i <= n + m; ++i){
            fu = Find(i);
            if(fu == i and du[fu] == 0){
                q.push(fu);
                //cout << "fu: " << fu << endl;
                ans[fu] = 1;
            }
        }
        bfs();
        bool flag = true;
        for(int i = 1; i <= n + m; ++i){
            ans[i] = ans[Find(i)];
            if(ans[i] == 0){
                flag = false;
                break;
            }
        }
        if(!flag){
            puts("No");
            continue;
        }
        puts("Yes");
        for(int i = 1; i <= n; ++i){
            if(i != 1)  printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        for(int i = n + 1; i <= n + m; ++i){
            if(i != n + 1)  printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
3 4
>>>>
>>>>
>>>>
*/
