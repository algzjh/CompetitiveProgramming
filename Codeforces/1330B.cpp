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
int a[MAXN];
vector<PII> ans;
 
struct Segment_Tree{
    //线段树节点结构体
    struct Node{
        int left,right;//左右边界
        int mi,ma;//最小值 最大值
    }tree[MAXN*4];//空间开四倍
 
 
//向上更新
    void PushUp(int rt){
        tree[rt].mi=min(tree[rt<<1].mi,tree[rt<<1|1].mi);
        tree[rt].ma=max(tree[rt<<1].ma,tree[rt<<1|1].ma);
    }
 
//建立函数
    void Build(int rt,int L,int R){
        tree[rt].left=L;tree[rt].right=R;
        if(L==R) {tree[rt].mi=tree[rt].ma=0; return;}
        int mid=(tree[rt].left+tree[rt].right)>>1;
        Build(rt<<1,L,mid);//只有Build时LR才会变
        Build(rt<<1|1,mid+1,R);
        PushUp(rt);
    }
 
    int QueryMin(int rt,int L,int R){
        if(L<=tree[rt].left&&tree[rt].right<=R) return  tree[rt].mi;
        int mid=(tree[rt].left+tree[rt].right)>>1;
        int res=INF;
        if(L<=mid) res=min(res,QueryMin(rt<<1,L,R));
        if(R>mid)  res=min(res,QueryMin(rt<<1|1,L,R));
        return  res;
    }
 
    int QueryMax(int rt,int L,int R){
        if(L<=tree[rt].left&&tree[rt].right<=R) return  tree[rt].ma;//完全包含才产生贡献
        int mid=(tree[rt].left+tree[rt].right)>>1;
        int res=-INF;
        if(L<=mid) res=max(res,QueryMax(rt<<1,L,R));
        if(R>mid)  res=max(res,QueryMax(rt<<1|1,L,R));
        return  res;
    }
 
    void Update(int rt,int pos,int x){//把pos位的值改为x
        if(tree[rt].left==tree[rt].right) { tree[rt].mi += x; tree[rt].ma += x; return; }
        int mid=(tree[rt].left+tree[rt].right)>>1;
        if(pos<=mid) Update(rt<<1,pos,x);
        else Update(rt<<1|1,pos,x);
        PushUp(rt);
    }
}T1, T2;
 
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        ans.clear();
        int n;
        scanf("%d", &n);
        T1.Build(1, 1, n);
        T2.Build(1, 1, n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            T2.Update(1, a[i], 1);
        }
        for(int i = 1; i <= n - 1; ++i){
            // [1, i], [i + 1, n]
            T1.Update(1, a[i], 1);
            T2.Update(1, a[i], -1);
            int mi1 = T1.QueryMin(1, 1, i);
            int ma1 = T1.QueryMax(1, 1, i);
            if(mi1 == 1 and ma1 == 1){
                int mi2 = T2.QueryMax(1, 1, n - i);
                int ma2 = T2.QueryMin(1, 1, n - i);
                if(mi2 == 1 and ma2 == 1){
                    ans.emplace_back(mk(i, n - i));
                }
            }
        }
        printf("%d\n", ans.size());
        for(auto it : ans){
            printf("%d %d\n", it.fi, it.se);
        }
    }
}
