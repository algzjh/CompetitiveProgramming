# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
map<PII, bool> mp;
map<PII, int> mp2;
char s[MAXN];
 
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        mp.clear();
        mp2.clear();
        mp[mk(0, 0)] = true;
        mp2[mk(0, 0)] = 0;
        PII pre = mk(0, 0), nxt;
        int ansL = 0, ansR = n + 1;
        for(int i = 1; i <= n; ++i){
            nxt = pre;
            if(s[i] == 'L')  nxt.fi -= 1;
            else if(s[i] == 'R')  nxt.fi += 1;
            else if(s[i] == 'U')  nxt.se += 1;
            else nxt.se -= 1;
            if(mp[nxt]){
                if(i - mp2[nxt] < ansR - ansL + 1){
                    ansL = mp2[nxt] + 1;
                    ansR = i;
                }
                mp2[nxt] = i;
            }else{
                mp[nxt] = true;
                mp2[nxt] = i;
            }
            pre = nxt;
        }
        if(ansL == 0 and ansR == n + 1)  printf("-1\n");
        else printf("%d %d\n", ansL, ansR);
    }
    return 0;
}
