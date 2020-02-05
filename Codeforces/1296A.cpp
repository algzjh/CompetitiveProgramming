# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if(sum&1){
            printf("YES\n");
        }else{
            bool odd = false, even = false;
            for(int i = 1; i <= n; ++i){
                if(a[i]&1)  odd = true;
                else even = true;
                if(odd and even){
                    break;
                }
            }
            printf("%s\n", (odd and even) ? "YES" : "NO");
        }
    }
    return 0;
}
 
/*
5
2
2 3
4
2 2 8 8
3
3 3 3
4
5 5 5 5
4
1 1 1 1
 */
