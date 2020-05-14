#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int n, f[MAXN][20], a[MAXN];

void ST_prework(){
    for(int i=1;i<=n;i++) f[i][0]=a[i];
    int t=log2(n)+1;
    for(int j=1;j<t;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

int ST_query(int l,int r){
    int k=log2(r-l+1);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
    int n;
    scanf("%d", &n);
    return 0;
}
/*

 */