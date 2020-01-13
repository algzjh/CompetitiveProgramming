#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e3 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n, p[MAXN], c[MAXN], a[MAXN];
vector<int> E[MAXN];

vector<int> dfs(int u){
    vector<int> ans;
    for(int i = 0; i < E[u].size(); ++i){
        vector<int> tmp = dfs(E[u][i]);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    if(u == 0)  return ans;
    if(ans.size() < c[u]){
        printf("NO\n");
        exit(0);
    }
    vector<int> new_ans;
    new_ans.resize(ans.size() + 1);
    for(int i = 0; i < c[u]; ++i){
        new_ans[i] = ans[i];
    }
    new_ans[c[u]] = u;
    for(int i = c[u]; i < ans.size(); ++i){
        new_ans[i+1] = ans[i];
    }
    ans = new_ans;
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &p[i], &c[i]);
        E[p[i]].emplace_back(i);
    }
    vector<int> ans = dfs(0);
    printf("YES\n");
    for(int i = 0; i < n; ++i){
//        cout << ans[i] << endl;
        a[ans[i]] = i + 1;
    }
    for(int i = 1; i <= n; ++i){
        if(i != 1)  printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
