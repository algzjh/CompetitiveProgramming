#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
map<string, int> dom, kattis;


void init(){
    dom.clear();
    kattis.clear();
}

int main(){
    int n;
    cin >> n;
    string result;
    for(int i = 1; i <= n; ++i){
        cin >> result;
        dom[result] += 1;
    }
    for(int i = 1; i <= n; ++i){
        cin >> result;
        kattis[result] += 1;
    }
    int ans = 0;
    for(auto item : dom){
        ans += min(item.second, kattis[item.first]);
    }
    printf("%d\n", ans);
    return 0;
}
/*
5
correct
wronganswer
correct
correct
timelimit
wronganswer
correct
timelimit
correct
timelimit
 */
