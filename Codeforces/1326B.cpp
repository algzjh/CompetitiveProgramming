#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
typedef unsigned long long LL;
typedef pair<int, int> PII;
int a[MAXN], b[MAXN];
 
 
int main(){
    int n;
    scanf("%d", &n);
    int ma = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
        if(i == 1){
            a[1] = b[i];
        }else{
            a[i] = b[i] + ma;
        }
        ma = max(ma, a[i]);
    }
    for(int i = 1; i <= n; ++i){
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
}
