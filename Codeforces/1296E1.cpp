# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 200 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN];
int ans[MAXN];
 
 
int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    int p = -1, q = -1;
    bool flag = true;
    for(int i = 1; i <= n; ++i){
        if((s[i]-'a') >= p){
            p = (s[i] - 'a');
            ans[i] = 0;
        }else if((s[i]-'a') >= q){
            q = (s[i] - 'a');
            ans[i] = 1;
        }else{
            flag = false;
            break;
        }
    }
    if(flag){
        printf("YES\n");
        for(int i = 1; i <= n; ++i){
            printf("%d", ans[i]);
        }
        printf("\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
