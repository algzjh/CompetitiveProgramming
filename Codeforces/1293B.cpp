# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;


int main(){
    int n;
    scanf("%d", &n);
    double ans = 0;
    if(n == 1){
        ans = 1.0;
    }else{
        while(n){
            ans += 1.0 / n;
            n -= 1;
        }
        /*
        if(n&1){
            ans = (n+1)/2.0/n;
            n /=2;
        }
        while(n){
            if(n == 1){
                ans += 1;
            }else{
                ans += (n/2.0)/n;
            }
            n /= 2;
        }
         */
    }
    printf("%.6f\n", ans);
    return 0;
}
/*
t1/n + (t2)/(n - t1) + (t3)/(n - t1 - t2) + ... +
*/
