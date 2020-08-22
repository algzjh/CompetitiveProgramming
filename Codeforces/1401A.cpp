/*
 * Author: algzjh
 * Date: 22/8/2020
 * Comment: math
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
        int n, k;
        scanf("%d%d", &n, &k);
        if(k > n){
            printf("%d\n", k - n);
        }else{
            printf("%d\n", k%2 == n%2 ? 0 : 1);
        }
    }
    return 0;
}
/*
*/
