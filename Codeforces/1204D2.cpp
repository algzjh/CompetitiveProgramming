#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
char s[MAXN];
vector<PII> v;
 
int main(){
    v.clear();
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; ++i){
        if(s[i] == '0' && !v.empty() && v.back().fi == '1')  v.pop_back();
        else v.emplace_back(mk(s[i], i));
    }
    for(auto it : v){
//        cout << it.fi << " " << it.se << endl;
        if(it.fi == '1')  s[it.se] = '0';
    }
    printf("%s\n", s + 1);
    return 0;
}
