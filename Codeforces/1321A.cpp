#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
int r[MAXN], b[MAXN];


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &r[i]);
    }
    int large = 0, equal = 0, less = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
        if(r[i] > b[i])  ++large;
        else if(r[i] == b[i])  ++equal;
        else ++less;
    }
    int ans = 0;
    if(less == 0){
        if(large == 0)  ans = -1;
        else  ans = 1;
    }else{
        if(large == 0)  ans = -1;
        else{
            ans = int(ceil(1.0 * less / large));
            if(less % large == 0)  ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
