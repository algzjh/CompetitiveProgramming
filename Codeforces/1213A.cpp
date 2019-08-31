#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int fa[MAXN], sz[MAXN];
LL a[MAXN];
 
 
int main(){
    int n;
    scanf("%d", &n);
    int odd = 0, x;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        if(x & 1) ++odd;
    }
    printf("%d\n", min(odd, n - odd));
    return 0;
}
