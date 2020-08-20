/*
 * Author: algzjh
 * Date: 20/8/2020
 * Comment: math, brute force, 900
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;
const LL INF = 1e18;
const int MOD = 998244353;


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
         LL n;
         scanf("%lld", &n);
         int ans = 0;
         while(n != 1 and ans <= 1000){
             if(n % 6 == 0)  n /= 6;
             else n *= 2;
             ++ans;
         }
         printf("%d\n", ans > 1000 ? -1 : ans);
    }
    return 0;
}
/*
1: 0
3: 2
6: 1
9: 4
18: 3
*/
