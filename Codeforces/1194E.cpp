#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 5e3 + 5;
const int MAXM = 1e4 + 5;
int bit[MAXM];
int front, rear;
PII q[MAXN];


struct Seg{
    int w, l, r;
}h[MAXN], v[MAXN];

bool cmp(const Seg &u, const Seg &v){
    return u.w < v.w;
}

int lowbit(int x) {return x & (-x);}

int ask(int x){
    int sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= lowbit(x);
    }
    return sum;
}

void add(int x, int v){
    while(x <= MAXM){
        bit[x] += v;
        x += lowbit(x);
    }
}

void init(){
    memset(bit, 0, sizeof(bit));
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    int x1, y1, x2, y2, ch = 0, cv = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 == x2){
            v[++cv].w = x1;
            v[cv].l = min(y1, y2);
            v[cv].r = max(y1, y2);
        }else{
            h[++ch].w = y1;
            h[ch].l = min(x1, x2);
            h[ch].r = max(x1, x2);
        }
    }
    sort(h + 1, h + ch + 1, cmp);
    sort(v + 1, v + cv + 1, cmp);
    LL ans = 0;
    for(int i = 1; i <= ch; ++i){ // horizontal
        front = rear = 1;
        for(int j = 1; j <= cv; ++j){ // vertical
            if(v[j].w >= h[i].l && v[j].w <= h[i].r && v[j].l <= h[i].w && v[j].r >= h[i].w){
                // intersect
                q[rear] = mk(v[j].r, v[j].w);
                ++rear;
                add(v[j].w + MAXN, 1);
            }
        }
        sort(q + front, q + rear);
        for(int k = i + 1; k <= ch; ++k){
            if(h[k].r <= h[i].l || h[k].l >= h[i].r) continue;
            while(front < rear && q[front].fi < h[k].w){ // pay attention to conditions, don't miss
                add(q[front].se + MAXN, -1);
                ++front;
            }
            LL tmp = ask(h[k].r + MAXN) - ask(h[k].l - 1 + MAXN);
            if(tmp != 0)  ans += ((tmp * (tmp - 1)) >> 1);
        }
        while(front < rear){
            add(q[front].se + MAXN, -1);
            ++front;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
