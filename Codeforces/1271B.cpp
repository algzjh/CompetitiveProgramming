#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 200 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<LL, LL> PLL;
char s[MAXN], s2[MAXN];
int n;
vector<int> ans;
 
bool check(){
    for(int i = 2; i <= n; ++i){
        if(s[i] != s[1])  return false;
    }
    return true;
}
 
 
void init(){
    ans.clear();
}
 
int main(){
    scanf("%d%s", &n, s + 1);
    init();
    for(int i = 1; i <= n; ++i){
        s2[i] = s[i];
    }
    if(n == 1){
        printf("0\n");
        return 0;
    }
    bool flag = true;
    int p = 2;
    while(p < n){
        if(s[p] != s[1]){
            s[p] = (s[p] == 'B' ? 'W' : 'B');
            s[p + 1] = (s[p + 1] == 'B' ? 'W' : 'B');
            ans.emplace_back(p);
        }
        ++p;
    }
    if(s[p] != s[1])  flag = false;
    if(flag){
        int sz = ans.size();
        printf("%d\n", sz);
        for(int i = 0; i < sz; ++i){
            if(i != 0)  printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        return 0;
    }
    for(int i = 1; i <= n; ++i){
        s[i] = s2[i];
    }
    flag = true;
    ans.clear();
    s[1] = (s[1] == 'B' ? 'W' : 'B');
    s[2] = (s[2] == 'B' ? 'W' : 'B');
    ans.emplace_back(1);
    p = 2;
    while(p < n){
        if(s[p] != s[1]){
            s[p] = (s[p] == 'B' ? 'W' : 'B');
            s[p + 1] = (s[p + 1] == 'B' ? 'W' : 'B');
            ans.emplace_back(p);
        }
        ++p;
    }
    if(s[p] != s[1])  flag = false;
    if(flag){
        int sz = ans.size();
        printf("%d\n", sz);
        for(int i = 0; i < sz; ++i){
            if(i != 0)  printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        return 0;
    }else{
        printf("-1\n");
    }
    return 0;
}
