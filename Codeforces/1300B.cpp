# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= 2 * n; ++i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 2 * n + 1);
        printf("%d\n", abs(a[n + 1] - a[n]));
//        if(n & 1){
//
//        }else{
//            int t1 = abs(a[n/2] - a[(3*n)/2]);
//            int t2 = abs(a[(n+1)/2] - a[(3*n + 2)/2]);
//            printf("%d\n", min(t1, t2));
//        }
    }
    return 0;
}
/*
3
4
13 16 2 3 20 18 5 4
 */
