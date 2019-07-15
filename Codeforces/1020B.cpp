#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e3;
int son[MAXN], in[MAXN], ans[MAXN];
queue<int> q;
 
void init(int n){
    for(int i = 1; i <= n; ++i){
        in[i] = 0;
        ans[i] = i;
    }
}
 
int Find(int u){
    return ans[u] == u ? u : ans[u] = Find(ans[u]);
}
 
int main(){
    int n;
    scanf("%d", &n);
    init(n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &son[i]);
        ++in[son[i]];
    }
    for(int i = 1; i <= n; ++i){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(), v = son[u];
        q.pop();
        --in[v];
        ans[u] = v;
        if(in[v] == 0){
            q.push(v);
        }
    }
    for(int i = 1; i <= n; ++i){
        if(i != 1) printf(" ");
        printf("%d", Find(i));
    }
    printf("\n");
    return 0;
}
