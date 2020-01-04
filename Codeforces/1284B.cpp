#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
vector<int> v[MAXN];
vector<int> vmin;
vector<int> tmax;
vector<PII> vmax;
bool mark[MAXN];
int sum[MAXN];
 
struct Node{
    int mi, ma;
}w[MAXN];
 
void init(){
    vmin.clear();
    vmax.clear();
    tmax.clear();
    memset(mark, false, sizeof(mark));
    memset(sum, 0, sizeof(sum));
}
 
int main(){
    init();
    int n, l, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &l);
        w[i].mi = INF, w[i].ma = -INF;
        bool flag = true;
        for(int j = 1; j <= l; ++j){
            scanf("%d", &x);
            v[i].emplace_back(x);
            w[i].mi = min(w[i].mi, x);
            w[i].ma = max(w[i].ma, x);
            if(j > 1 && v[i][j - 1] > v[i][j - 2])  flag = false;
        }
        mark[i] = flag;
        vmin.emplace_back(w[i].mi);
        vmax.emplace_back(mk(w[i].ma, i));
    }
    sort(vmin.begin(), vmin.end());
    sort(vmax.begin(), vmax.end());
    LL ans = 0;
    for(auto it : vmax){
//        cout << it.fi  << " " << it.se << " ";
        tmax.emplace_back(it.fi);
    }
    for(int i = 0; i < n; ++i){
        if(i != 0){
            sum[i] = sum[i-1] + (!mark[vmax[i].se]);
        }else{
            sum[i] = (!mark[vmax[i].se]);
        }
    }
//    cout << endl;
//    for(int i = 1; i <= n; ++i){
//        cout << mark[i] << " ";
//    }
//    cout << endl;
    int tmp = 0;
    for(int i = 1; i <= n; ++i){
        if(not mark[i])  ++tmp;
    }
    for(int i = 1; i <= n; ++i){
//        cout << w[i].mi << " " << w[i].ma << endl;
        if(not mark[i])  ans += n;
        else{
            int p = ( upper_bound(tmax.begin(), tmax.end(), w[i].mi) - tmax.begin() );
            ans += n - p;
            ans += sum[p - 1];
        }
//        cout << "ans: " << ans << endl;
    }
    printf("%lld\n", ans);
    return 0;
}
