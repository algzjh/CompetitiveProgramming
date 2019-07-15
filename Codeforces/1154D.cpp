#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
 
int main(){
    int n, b, a, x;
    scanf("%d%d%d", &n, &b, &a);
    int nowb = b, nowa = a, ans = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &x);
        if(x){
            if(nowb > 0){
                if(nowa == a){
                    nowa -= 1;
                }else{
                    nowb -= 1;
                    nowa = min(a, nowa + 1);
                }
            }else{
                nowa -= 1;
            }
        }else{
            if(nowa > 0){
                nowa -= 1;
            }else{
                nowb -= 1;
            }
        }
        if((nowa == 0 && nowb == 0) || i == n){
            ans = i;
            break;
        }
    }
    //if(nowa > 0 || nowb > 0)  ans += nowa + nowb;
    printf("%d\n", ans);
    return 0;
}
