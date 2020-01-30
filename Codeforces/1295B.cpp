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
char s[MAXN];
int prefix[MAXN];
map<int, bool> mp;
vector<int> ans;
 
void init(){
    memset(prefix, 0, sizeof(prefix));
    mp.clear();
    ans.clear();
}
 
int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        init();
        int n, x;
        scanf("%d%d", &n, &x);
        scanf("%s", s + 1);
        for(int i = 1; i <= n; ++i){
            prefix[i] = prefix[i-1];
            if(s[i] == '0')  ++prefix[i];
            else  --prefix[i];
            mp[prefix[i]] = true;
        }
        if(prefix[n] == 0){
            printf("%d\n", mp[x] ? -1 : 0);
            continue;
        }
        bool flag = false;
        int cnt;
        if(x == 0){
            ans.emplace_back(0);
            flag = true;
        }
        for(int i = 1; i <= n; ++i){
            if((x-prefix[i])%prefix[n] == 0){
                cnt = (x-prefix[i])/prefix[n];
                if(cnt >= 0){
                    ans.emplace_back(i + (x-prefix[i])/prefix[n] * n);
                    flag = true;
                }
            }
        }
        if(flag){
            int sz = ans.size();
            printf("%d\n", sz);
//            for(int i = 0; i < sz; ++i){
//                if(i != 0)  printf(" ");
//                printf("%d", ans[i]);
//            }
//            printf("\n");
        }else{
            printf("0\n");
        }
    }
    return 0;
}
