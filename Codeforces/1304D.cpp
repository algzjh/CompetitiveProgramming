#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
char s[MAXN];
LL mi[MAXN], ma[MAXN], t[MAXN];
 
 
void discretize(LL a[], int n){
    for(int i = 1; i <= n; ++i)  t[i] = a[i];
    sort(t + 1, t + n + 1);
    int m = unique(t + 1, t + n + 1) - (t + 1);
    for(int i = 1; i <= n; ++i){
        a[i] = lower_bound(t + 1, t + m + 1, a[i]) - t;
    }
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d%s", &n, s + 1);
        mi[1] = ma[1] = 0;
        for(int i = 1; i <= n - 1; ++i){
            if(s[i] == '>'){
                mi[i + 1] = mi[i] - INF;
                ma[i + 1] = ma[i] - 1;
            }else{
                mi[i + 1] = mi[i] + 1;
                ma[i + 1] = ma[i] + INF;
            }
        }
        discretize(mi, n);
        discretize(ma, n);
        for(int i = 1; i <= n; ++i){
            if(i != 1)  printf(" ");
            printf("%d", mi[i]);
        }
        printf("\n");
        for(int i = 1; i <= n; ++i){
            if(i != 1)  printf(" ");
            printf("%d", ma[i]);
        }
        printf("\n");
    }
    return 0;
}
/*
5 > 4 > 3 < 7 > 2 > 1 < 6
LIS: 2
4 > 3 > 1 < 7 > 5 > 2 < 6
LIS: 3
 
4 > 3 > 2 > 1 < 5
LIS: 2
5 > 4 > 2 > 1 < 3
LIS: 2
 */
