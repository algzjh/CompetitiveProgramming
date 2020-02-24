#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
int a[5];
 
 
bool cmp(int x, int y){
    return x > y;
}
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int ans = 0, x;
        for(int i = 1; i <= 3; ++i){
            scanf("%d", &a[i]);
            if(a[i] > 0){
                --a[i];
                ++ans;
            }
        }
        sort(a + 1, a + 3 + 1, cmp);
        if(a[1] >= 1 and a[2] >= 1){
            --a[1], --a[2], ++ans;
        }
        if(a[1] >= 1 and a[3] >= 1){
            --a[1], --a[3], ++ans;
        }
        if(a[2] >= 1 and a[3] >= 1){
            --a[2], --a[3], ++ans;
        }
        if(a[1] >= 1 and a[2] >= 1 and a[3] >= 1)  ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
 
/*
 
1 0 0
0 1 0
0 0 1
 
0 1 1
1 0 1
1 1 0
 
1 1 1
*/
