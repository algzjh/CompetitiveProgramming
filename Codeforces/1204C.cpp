#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
char s[105][105];
int f[105][105];
int p[MAXN], n, m;
vector<int> ans;
 
void init(){
    memset(f, 0x3f, sizeof(f));
    ans.clear();
}
 
void floyd(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}
 
int main(){
    init();
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%s", s[i] + 1);
        f[i][i] = 0;
        for(int j = 1; j <= n; ++j){
            if(s[i][j] == '1'){
                f[i][j] = 1;
            }
        }
    }
 
    floyd();
 
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i){
        scanf("%d", &p[i]);
    }
 
//    for(int i = 1; i <= n; ++i){
//        for(int j = 1; j <= n; ++j){
//            cout << f[i][j] << " ";
//        }
//        cout << endl;
//    }
 
    int c1 = 1, c2 = 2;
    ans.emplace_back(p[c1]);
    while(c1 <= m and c2 <= m){
        if(f[p[c1]][p[c2]] == c2 - c1){
            if(c2 == m)  ans.emplace_back(p[c2]);
            ++c2;
        }else{
            ans.emplace_back(p[c2-1]);
            c1 = c2 - 1;
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for(int i = 0; i < sz; ++i){
        if(i != 0)  printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
 
