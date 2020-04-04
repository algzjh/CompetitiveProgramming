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
int L[MAXN];
 
struct Node{
    int l, r;
}seg[MAXN];
 
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i){
        scanf("%d", &L[i]);
    }
    bool flag = true;
    for(int i = 1; i <= m-1; ++i){
        seg[i].l = i;
        seg[i].r = i + L[i] - 1;
        if(seg[i].r > n){
            flag = false;
            break;
        }
    }
    seg[m].l = n - L[m] + 1;
    seg[m].r = n;
    if(seg[m].l <= seg[m-1].l)  flag = false;
    if(not flag){
        printf("-1\n");
        return 0;
    }
    for(int i = m - 1; i >= 1; --i){
        if(seg[i].r < seg[i+1].l - 1){
            int add = seg[i+1].l - seg[i].r - 1;
            seg[i].l += add;
            seg[i].r += add;
        }
    }
    if(seg[1].l > 1){
        printf("-1");
    }else{
        for(int i = 1; i <= m; ++i){
            printf("%d%c", seg[i].l, i == n ? '\n': ' ');
        }
    }
}
 
/*
5 5
1 1 1 3 1
*/
