/*
 * Author: algzjh
 * Date: 11/8/20
 * Comment:  STL, implementation, greedy, 1500
 */
#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
const int MAXM = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
char s[MAXN];
int ans[MAXN];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        queue<int> q[2];
        int colMax = 0, currentNum;
        for(int i = 1; i <= n; ++i){
            currentNum = s[i] - '0';
            if(q[1 - currentNum].size() > 0){
                int col = q[1 - currentNum].front();
                q[1 - currentNum].pop();
                ans[i] = col;
                q[currentNum].push(col);
            }else{
                ans[i] = ++colMax;
                q[currentNum].push(colMax);
            }
        }
        printf("%d\n", colMax);
        for(int i = 1; i <= n; ++i){
            printf("%d%c", ans[i], i == n ? '\n': ' ');
        }
    }
    return 0;
}
