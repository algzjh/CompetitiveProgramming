#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
char ans[MAXN];

struct Node{
    int s, e, id;
}seg[MAXN];


bool cmp(const Node& u, const Node& v){
    if(u.s == v.s)  return u.e < v.e;
    return u.s < v.s;
}


int main(){
    int _;
    scanf("%d", &_);
    int cas = 1;
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &seg[i].s, &seg[i].e);
            seg[i].id = i;
        }
        sort(seg + 1, seg + n + 1, cmp);
        int cend = 0, jend = 0;
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            if(cend <= seg[i].s){
                ans[seg[i].id] = 'C';
                cend = seg[i].e;
            }else if(jend <= seg[i].s){
                ans[seg[i].id] = 'J';
                jend = seg[i].e;
            }else{
                flag = false;
                break;
            }
        }
        printf("Case #%d: ", cas++);
        if(not flag){
            printf("IMPOSSIBLE\n");
        }else{
            ans[n + 1] = '\0';
            printf("%s\n", ans + 1);
        }
    }
}
/*

 */
