/*
 * Author: algzjh
 * Date: 20/8/2020
 * Comment: math, 900
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

int solve(int x){
    int cnt[4];
    cnt[2] = cnt[3] = 0;
    bool flag = true;
    for(int i = 2; i <= 3; ++i){
        if(x % i == 0){
            x /= i;
            ++cnt[i];
            --i;
        }
    }
    if(x == 2 or x == 3)  ++cnt[x];
    else if(x != 1)  flag = false;
    if(cnt[2] > cnt[3])  flag = false;
    return flag ? 2 * cnt[3] - cnt[2] : -1;
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        printf("%d\n", solve(n));
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
