#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
LL a[MAXN];
 
 
int main(){
    LL n, k;
    scanf("%lld%lld", &n, &k);
    for(int i = 1;i <= n; ++i){
        scanf("%lld", &a[i]);
    }
    if(n == 1){
        printf("%lld\n", a[1] + k);
        return 0;
    }
    sort(a + 1, a + n + 1);
    LL mid = n/2 + 1;
    LL R = mid + 1;
    while(R <= n && a[R] == a[mid]) ++R;
    while(R<=n && k>0 && R - mid <= k){
        if((a[R] - a[mid])*(R-mid) <= k){
            k -= (a[R] - a[mid])*(R-mid);
            a[mid] = a[R];
            while(R<= n && a[R] == a[mid]) ++R;
        }else{
            a[mid] += k/(R-mid);
            k=0;
        }
    }
    if(R>n && k>0){
        a[mid] += k/(n+1-mid);
    }
    printf("%lld\n", a[mid]);
    return 0;
}
/*
10
34 24 21 42 80 2 4 200 32 1
 
5
2 3 1 100 100
 
15 239017
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1000000000
*/
