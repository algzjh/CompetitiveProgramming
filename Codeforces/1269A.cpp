#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 20;
const int INF = 0x3f3f3f3f;
 
 
 
int main(){
    int n, a, b;
    scanf("%d", &n);
    if(n&1){
        a = 9 * n, b = 8 * n;
    }else{
        a = 3 * n, b = 2 * n;
    }
    printf("%d %d\n",a, b);
    return 0;
}
