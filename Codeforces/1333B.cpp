#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[MAXN], b[MAXN];
map<int, bool> vis;
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        vis.clear();
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
        }
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            if(a[i] > b[i]){
                if(not vis[-1]){
                    flag = false;
                    break;
                }
            }else if(a[i] < b[i]){
                if(not vis[1]){
                    flag = false;
                    break;
                }
            }
            vis[a[i]] = true;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
}
