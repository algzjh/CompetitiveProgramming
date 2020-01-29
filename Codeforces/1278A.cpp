# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 100 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char p[MAXN], h[MAXN];
int cntp[26], cnth[MAXN][26];
 
 
void init(){
    memset(cntp, 0, sizeof(cntp));
    memset(cnth, 0, sizeof(cnth));
}
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s%s", p + 1, h + 1);
        init();
        int lenp = strlen(p + 1);
        for(int i = 1; i <= lenp; ++i){
            ++cntp[p[i]-'a'];
        }
        int lenh = strlen(h + 1);
        for(int i = 1; i <= lenh; ++i){
            for(int j = 0; j < 26; ++j){
                cnth[i][j] = cnth[i-1][j];
            }
            ++cnth[i][h[i]-'a'];
        }
        if(lenh < lenp){
            printf("NO\n");
        }else{
            bool flag = false;
            int  num;
            for(int i = 1; i <= lenh - lenp + 1; ++i){
                for(num = 0; num < 26; ++num){
                    if(cntp[num] != cnth[i + lenp - 1][num] - cnth[i-1][num]){
                        break;
                    }
                }
                if(num == 26){
                    flag = true;
                    break;
                }
            }
            printf("%s\n", flag ? "YES" : "NO");
        }
    }
    return 0;
}
