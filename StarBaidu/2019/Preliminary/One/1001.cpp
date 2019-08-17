#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int f[MAXN], g[MAXN];

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &f[i]);
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &g[i]);
        }
        int flag = 1, up, down;
        for(int i = n - 1; i >= 0; --i){
            if(f[i] == 0 && g[i] == 0){
                continue;
            }else if(f[i] > 0 && g[i] == 0){
                flag = 2;
                break;
            }else if(f[i] == 0 && g[i] > 0){
                flag = 3;
                break;
            }else if(f[i] > 0 && g[i] > 0){
                up = f[i];
                down = g[i];
                flag = 4;
                break;
            }
        }
        if(flag == 2){
            printf("1/0\n");
        }else if(flag == 3){
            printf("0/1\n");
        }else if(flag == 4){
            int g = gcd(up, down);
            printf("%d/%d\n", up/g, down/g);
        }
    }
    return 0;
}


/*

*/
