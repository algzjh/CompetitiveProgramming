# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 2e2 + 5;
const int MAXM = 8e4 + 5;
const int MOD = 1e9 + 7;
const LL INF = 1e18;
typedef long long LL;
typedef pair<double, int> PDI;
char ans[MAXM];

struct Node{
    int x, y;
}s[MAXN], f[MAXN];


bool cmp(const Node &u, const Node &v){
    if(u.x == v.x)  return u.y < v.y;
    return  u.x < v.x;
}


int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int max_x = 0, max_y = 0, end = 0;
    for(int i = 1; i <= k; ++i){
        scanf("%d%d", &s[i].x, &s[i].y);
        max_x = max(max_x, s[i].x);
        max_y = max(max_y, s[i].y);
    }
    for(int i = 1; i < max_x; ++i){
        ans[end++] = 'U';
    }
    for(int i = 1; i < max_y; ++i){
        ans[end++] = 'L';
    }
    for(int i = 1; i <= k; ++i){
        scanf("%d%d", &f[i].x, &f[i].y);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < m; ++j){
            ans[end++] = (i&1) ? 'R' : 'L';
        }
        if(i != n)  ans[end++] = 'D';
    }
    ans[end] = '\0';
    printf("%d\n", end);
    printf("%s\n", ans);
    return 0;
}
