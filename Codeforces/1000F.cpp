/*
 * Educational Codeforces Round 46
 * 1000F One Occurrence
 * Segment Tree
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(5e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN], pre[MAXN], pos[MAXN], ans[MAXN];
int n, q;

struct Node{
    int left, right, mi, mid;
}tree[MAXN * 4];

void PushUp(int rt){
    if(tree[rt<<1].mi < tree[rt<<1|1].mi){
        tree[rt].mi = tree[rt<<1].mi;
        tree[rt].mid = tree[rt<<1].mid;
    }else{
        tree[rt].mi = tree[rt<<1|1].mi;
        tree[rt].mid = tree[rt<<1|1].mid;
    }
}

void Build(int rt, int L, int R){
    tree[rt].left = L, tree[rt].right = R;
    if(L == R) {tree[rt].mi = n + 1; tree[rt].mid = L; return; }
    int mid = (tree[rt].left + tree[rt].right) >> 1;
    Build(rt<<1, L, mid);
    Build(rt<<1|1, mid + 1, R);
    PushUp(rt);
}

PII QueryMin(int rt,int L, int R){
    if(L <= tree[rt].left && tree[rt].right <= R)  return mk(tree[rt].mi, tree[rt].mid);
    int mid = (tree[rt].left + tree[rt].right) >> 1;
    PII res = mk(INF, INF);
    if(L <= mid)  res = min(res, QueryMin(rt<<1, L, R));
    if(R > mid)  res = min(res, QueryMin(rt<<1|1, L, R));
    return res;
}

void Update(int rt, int pos, int x){
    if(tree[rt].left == tree[rt].right) {tree[rt].mi = x; return;}
    int mid = (tree[rt].left + tree[rt].right) >> 1;
    if(pos <= mid)  Update(rt<<1, pos, x);
    else  Update(rt<<1|1, pos, x);
    PushUp(rt);
}

struct Node2{
    int l, r, id;
}Q[MAXN];

bool cmp(const Node2 &u, const Node2 &v){
    return u.r < v.r;
}

void init(){
    memset(pos, -1, sizeof(pos));
}

void displaySeg(){
    for(int i = 1; i <= n; ++i){
        cout << QueryMin(1, i, i).fi << " ";
    }
    cout << endl;
}

int main(){
    while(~scanf("%d", &n)){
        init();
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            pre[i] = pos[a[i]];
            pos[a[i]] = i;
        }

//        for(int i = 1; i <= n; ++i){
//            cout<<pre[i]<<" ";
//        }
//        cout<<endl;

        scanf("%d", &q);
        for(int i = 1; i <= q; ++i){
            scanf("%d%d", &Q[i].l, &Q[i].r);
            Q[i].id = i;
        }
        sort(Q + 1, Q + q + 1, cmp);
        Build(1, 1, n);
        int now = 1;

//        displaySeg();

        for(int i = 1; i <= q; ++i){
            while(now <= Q[i].r){
                if(pre[now] != -1)  Update(1, pre[now], n + 1);
                Update(1, now, pre[now]);
                ++now;
            }
            auto t = QueryMin(1, Q[i].l, Q[i].r);
            if(t.fi < Q[i].l)  ans[Q[i].id] = a[t.se];
            else ans[Q[i].id] = 0;
//            cout << "L: " << Q[i].l << " " << "R: "<< Q[i].r << endl;
//            displaySeg();
        }
        for(int i = 1; i <= q; ++i){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
/*
10
5 9 6 4 8 7 4 9 7 6
10
4 9
4 7
4 7
4 8
9 10
4 9
4 8
1 5
4 4
2 5

8
8
8
8
6
8
8
8
4
9
*/
