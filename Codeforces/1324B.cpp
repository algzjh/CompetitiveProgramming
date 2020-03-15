#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
int a[MAXN], L[MAXN], R[MAXN];
 
 
void init(int n){
    for(int i = 1; i <= n; ++i){
        L[i] = 0;
        R[i] = n + 1;
    }
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        init(n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(L[a[i]] == 0){
                L[a[i]] = i;
            }
        }
        for(int i = n; i >= 1; --i){
            if(R[a[i]] == n + 1){
                R[a[i]] = i;
            }
        }
        bool flag = false;
        for(int i = 1; i <= n; ++i){
            if(R[a[i]] - L[a[i]] >= 2){
                flag = true;
                break;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
