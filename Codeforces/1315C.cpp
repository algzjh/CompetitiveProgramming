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
typedef pair<LL, LL> PLL;
int b[MAXN], a[MAXN];
bool vis[MAXN];
set<int> s;


void init(){
    memset(vis, false, sizeof(vis));
    s.clear();
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        init();
        int n;
        scanf("%d", &n);
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
            if(vis[b[i]]){
                flag = false;
            }else{
                vis[b[i]] = true;
                a[2 * i - 1] = b[i];
            }
        }
        if(not flag){
            printf("-1\n");
        }else{
            for(int i = 1; i <= 2 * n; ++i){
                if(not vis[i])  s.insert(i);
            }
            for(int i = 2; i <= 2 * n; i += 2){
                auto it = s.upper_bound(a[i - 1]);
                if(it == s.end()){
                    flag = false;
                    break;
                }else{
                    a[i] = *it;
                    s.erase(it);
                }
            }
            if(not flag){
                printf("-1\n");
            }else{
                for(int i = 1; i <= 2 * n; ++i){
                    printf("%d%c",a[i], i == 2 * n ? '\n': ' ');
                }
            }
        }
    }
    return 0;
}
