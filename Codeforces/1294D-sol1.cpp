# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 4e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int y[MAXN], cnt[MAXN];
 
struct Node{
    int left, right;
    int mi, minpos;
}T[MAXN << 2];
 
void pushup(int rt){
    if(T[rt<<1].mi <= T[rt<<1|1].mi){
        T[rt].mi = T[rt<<1].mi;
        T[rt].minpos = T[rt<<1].minpos;
    }else{
        T[rt].mi = T[rt<<1|1].mi;
        T[rt].minpos = T[rt<<1|1].minpos;
    }
}
 
void build(int rt, int L, int R){
    T[rt].left = L; T[rt].right = R;
    if(L == R) {T[rt].mi = y[L]; T[rt].minpos = L; return;}
    int mid = (T[rt].left + T[rt].right) >> 1;
    build(rt<<1, L, mid);
    build(rt<<1|1, mid + 1, R);
    pushup(rt);
}
 
void update(int rt, int pos, int x){
    if(T[rt].left == T[rt].right) {T[rt].mi += x; return;}
    int mid = (T[rt].left + T[rt].right) >> 1;
    if(pos <= mid)  update(rt<<1, pos, x);
    else update(rt<<1|1, pos, x);
    pushup(rt);
}
 
PII queryMinandPos(int rt, int L, int R){
    if(L <= T[rt].left and T[rt].right <= R)  return mk(T[rt].mi, T[rt].minpos);
    int mid = (T[rt].left + T[rt].right) >> 1;
    PII res = mk(INF, INF);
    if(L <= mid)  res = min(res, queryMinandPos(rt<<1, L, R));
    if(R > mid)   res = min(res, queryMinandPos(rt<<1|1, L, R));
    return res;
}
 
int main(){
    int q, x;
    scanf("%d%d", &q, &x);
    memset(y, 0, sizeof(y));
    build(1, 1, x);
    for(int i = 1; i <= q; ++i){
        scanf("%d", &y[i]);
        int pos = (y[i] % x) + 1;
        update(1, pos, 1);
        PII res = queryMinandPos(1, 1, x);
        printf("%d\n", res.fi * x + res.se - 1);
    }
    return 0;
}
/*
1 + 2 + 3 + 4 + ... + 4 * 1e5
 
 
7 3
 
0,1,2,2,0,0,10
0,1,2,5,0,0,10
0,1,2,5,3,0,10
0,1,2,5,3,3,10
0,1,2,5,3,6,10
0,1,2,5,3,6,7
0,1,2,5,3,6,4
*/
