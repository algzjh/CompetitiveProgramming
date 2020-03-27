# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 5e4 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const LL INF = 1e18;
typedef long long LL;
typedef pair<double, int> PDI;
char s[MAXN], ans[3][MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d%s", &n, s + 1);
        int flag = 0;
        ans[1][1] = ans[2][1] = '1';
        for(int i = 2; i <= n; ++i){
            if(s[i] == '2'){
                if(flag != 0){
                    ans[3-flag][i] = '2';
                    ans[flag][i] = '0';
                }else{
                    ans[1][i] = ans[2][i] = '1';
                }
            }else if(s[i] == '1'){
                if(flag != 0){
                    ans[3-flag][i] = '1';
                    ans[flag][i] = '0';
                }else{
                    ans[1][i] = '1';
                    ans[2][i] = '0';
                    flag = 1;
                }
            }else if(s[i] == '0'){
                ans[1][i] = ans[2][i] = '0';
            }
        }
        ans[1][n + 1] = ans[2][n + 1] = '\0';
        printf("%s\n%s\n", ans[1] + 1, ans[2] + 1);
    }
    return 0;
}
