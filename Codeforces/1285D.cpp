#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n;
vector<int> a;

int solve(vector <int> &v, int bit){
    if(bit < 0)  return 0;
    vector <int> t0, t1;
    for(auto &i : v){
        if((i >> bit) & 1) t1.emplace_back(i);
        else t0.emplace_back(i);
    }
    if(t0.empty())  return solve(t1, bit - 1);
    if(t1.empty())  return solve(t0, bit - 1);
    return min(solve(t0, bit - 1), solve(t1, bit - 1)) + (1 << bit);
}

int main(){
    scanf("%d", &n);
    a.resize(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    printf("%d\n", solve(a, 29));
    return 0;
}
