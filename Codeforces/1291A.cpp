# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 3e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN], ans[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int odd = 0, num;
        for(int i = 1; i <= n; ++i){
            num = s[i] - '0';
            if(num&1)  odd += 1;
        }
        if(odd <= 1)  printf("-1\n");
        else{
            int p = 1;
            while(not ((s[p] - '0')&1))  ++p;
            int q = p + 1;
            while(not ((s[q] - '0')&1))  ++q;
            //cout << "p: " << p << " q: " << q << endl;
            strncpy(ans + 1, s + p, q - p + 1);
            ans[1 + q - p + 1] = '\0';
            printf("%s\n", ans + 1);
        }
    }
    return 0;
}
