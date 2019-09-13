#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 998244353;
const LL INF = 1e18;
LL s[MAXN];
int ans[MAXN];
 
struct Node{
    int left, right;
    int minpos;
    LL mi, add;
}T[MAXN<<2];
 
void pushUp(int rt){
    int lson = rt<<1, rson = rt<<1|1;
    if(T[rson].mi <= T[lson].mi)  T[rt].minpos = T[rson].minpos;
    else T[rt].minpos = T[lson].minpos;
    T[rt].mi = min(T[lson].mi, T[rson].mi);
}
 
void pushDown(int rt){
    if(T[rt].left < T[rt].right){
        int lson = rt<<1, rson = rt<<1|1;
        if(T[rt].add){
            T[lson].add += T[rt].add, T[rson].add += T[rt].add;
            T[lson].mi += T[rt].add, T[rson].mi += T[rt].add;
            T[rt].add = 0;
        }
    }
}
 
void build(int rt, int L, int R){
    T[rt].left = L, T[rt].right = R, T[rt].add = 0;
    if(L == R) {T[rt].mi = s[L]; T[rt].minpos = L; return;}
    int mid = (T[rt].left + T[rt].right)>>1;
    build(rt<<1, L, mid);
    build(rt<<1|1, mid+1, R);
    pushUp(rt);
}
 
PII queryLastMinAndPos(int rt, int L, int R){
    if(L <= T[rt].left && T[rt].right <= R)  return mk(T[rt].mi, T[rt].minpos);
    pushDown(rt);
    int mid = (T[rt].left + T[rt].right)>>1;
    PII res;
    if(R > mid)  res = queryLastMinAndPos(rt<<1|1, L, R);
    if(res.fi != 0 && L <= mid)  res = queryLastMinAndPos(rt<<1, L, R);
    pushUp(rt);
    return res;
}
 
void updateAdd(int rt, int L, int R, LL x){
    if(R < T[rt].left || T[rt].right < L)  return;
    if(L <= T[rt].left && T[rt].right <= R){
        T[rt].add += x; T[rt].mi += x;
        return;
    }
    pushDown(rt);
    int mid = (T[rt].left + T[rt].right)>>1;
    if(L <= mid)  updateAdd(rt<<1, L, R, x);
    if(R > mid)  updateAdd(rt<<1|1, L, R, x);
    pushUp(rt);
}
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &s[i]);
    }
    build(1, 1, n);
    for(int i = 1; i <= n; ++i){
        PII mp = queryLastMinAndPos(1, 1, n);
//        cout << mp.fi << " " << mp.se << endl;
        ans[mp.se] = i;
        updateAdd(1, mp.se, mp.se, INF);
        updateAdd(1, mp.se+1, n, -i);
    }
    for(int i = 1; i <= n; ++i){
        if(i != 1)  printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
/*
segment tree lazy propagation
*/
