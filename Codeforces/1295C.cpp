# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
char s[MAXN], t[MAXN];
int link[MAXN][26];
 
 
void init(int n){
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < 26; ++j){
            link[i][j] = -1;
        }
    }
}
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s%s", s + 1, t + 1);
        int lens = strlen(s + 1);
        int lent = strlen(t + 1);
        init(lens);
        for(int j = 0; j < 26; ++j)  link[lens][j] = -1;
        for(int i = lens - 1; i >= 0; --i){
            for(int j = 0; j < 26; ++j)  link[i][j] = link[i+1][j];
            link[i][s[i+1]-'a'] = i+1;
        }
        int p = 1, ans = 0, q, prep = 1;
        bool flag = true;
        while(p <= lent){
            q = 0;
            while(p <= lent and q <= lens and link[q][t[p]-'a'] != -1){
                q = link[q][t[p]-'a'];
                ++p;
            }
            if(p == prep){
                flag = false;
                break;
            }else{
                prep = p;
            }
            ++ans;
        }
        printf("%d\n", flag ? ans : -1);
    }
    return 0;
}
