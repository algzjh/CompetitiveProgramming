#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int m[MAXN], c[MAXN];


int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &m[i]);
    }
    for(int i = 1; i <= k; ++i){
        scanf("%d", &c[i]);
    }
    sort(m + 1, m + n + 1, greater<int>());
//    for(int i = 1; i <= n; ++i){
//        cout << m[i] << " ";
//    }
//    cout << endl;
    int ans = 0;
    for(int i = k, g = 0; i >= 1; --i){
        while(g + 1 <= n and m[g + 1] == i)  ++g;
        ans = max(ans, (g + c[i] - 1) / c[i]);
    }
    vector<vector<int>> res(ans);
    for(int i = 1; i <= n; ++i){
        res[(i-1)%ans].emplace_back(m[i]);
    }
    printf("%d\n", ans);
    for(int i = 0; i < ans; ++i){
        printf("%d", res[i].size());
        for(auto it : res[i])  printf(" %d", it);
        printf("\n");
    }
    return 0;
}
/*
4 3
1 2 2 3
4 1 1

*/
