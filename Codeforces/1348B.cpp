#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e2 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[MAXN], b[MAXN];
bool vis[MAXN];


void init(int n){
    for(int i = 1; i <= n; ++i){
        vis[i] = false;
    }
}


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, k;
        scanf("%d%d", &n, &k);
        init(n);
        int pos = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(not vis[a[i]]){
                vis[a[i]] = true;
                b[++pos] = a[i];
            }
        }
        if(pos > k){
            printf("-1\n");
            continue;
        }
        for(int i = 1; i <= n and pos < k; ++i){
            if(not vis[i]){
                vis[i] = true;
                b[++pos] = i;
            }
        }
        printf("%d\n", n * k);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= k; ++j){
                printf("%d", b[j]);
                if(i == n and j == k)  printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
