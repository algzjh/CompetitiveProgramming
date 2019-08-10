#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e6 + 5;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
 
void solve(int n){
    int y = 2;
    while((y+1)*y/2 <= n) ++y;
    int rem = n - y*(y-1)/2;
    printf("133");
    y-=2;
    while(rem > 0) {printf("7"); --rem;}
    while(y > 0)  {printf("3");--y;}
    printf("7\n");
}
 
int main(){
    int _, n;
    scanf("%d", &_);
    while(_--){
        scanf("%d", &n);
        solve(n);
    }
    return 0;
}
