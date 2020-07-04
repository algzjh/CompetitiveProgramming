#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e3+10;
const int MOD = 1e9+7;
LL C[MAXN][MAXN];

void Init(){
    C[0][0]=1;
    for(int i=1;i<MAXN;i++){
        C[i][0]=1;C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
        }
    }
}

int main(){
    Init();
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        LL ans = (C[n+m][n]*C[n+m][n]%MOD-C[n+m][m-1]*C[n+m][n-1]%MOD+MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}