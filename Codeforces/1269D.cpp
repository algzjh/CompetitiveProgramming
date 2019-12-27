#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
LL cnt[2];

int main(){
    int n;
    scanf("%d", &n);
    int x;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        cnt[(i&1)] += x/2;
        cnt[(i&1)^1] += x - x/2;
    }
    printf("%lld\n", min(cnt[0], cnt[1]));
    return 0;
}
/*
4
3 2 2 1
 */
