#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 5;
const int MOD = 998244353;
int a[MAXN], idx[MAXN];
int p[12] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
set<int> s;
int idx2col[35];


void init(){
    s.clear();
    memset(idx2col, 0, sizeof(idx2col));
}


int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        init();
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            for(int j = 1; j <= 11; ++j){
                if(a[i] % p[j] == 0){
                    idx[i] = j;
                    s.insert(j);
                    break;
                }
            }
        }
        int cnt = 0;
        for(auto it : s){
            ++cnt;
            idx2col[it] = cnt;
        }
        printf("%d\n", cnt);
        for(int i = 1; i <= n; ++i){
            printf("%d%c", idx2col[idx[i]], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
/*

*/
