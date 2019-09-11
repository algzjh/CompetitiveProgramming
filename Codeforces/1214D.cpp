#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e6 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int n, m;
char s[MAXN];
int cnt[MAXN], step[2][MAXN];

void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(step, -1, sizeof(step));
}

int getid(int r, int c){
    return (r-1) * m + (c-1);
}

bool ok(int r, int c){
    if(r < 1 || r > n || c < 1 || c > m)  return false;
    return s[getid(r, c)] != '#';
}

void dfs0(int r, int c, int s){
    if(ok(r + 1, c) && step[0][getid(r + 1, c)] == -1){
        step[0][getid(r + 1, c)] = s + 1;
        dfs0(r + 1, c, s + 1);
    }
    if(ok(r, c + 1) && step[0][getid(r, c + 1)] == -1){
        step[0][getid(r, c + 1)] = s + 1;
        dfs0(r, c + 1, s + 1);
    }
}

void dfs1(int r, int c, int s){
    if(step[0][getid(r, c)] != -1)  ++cnt[step[0][getid(r, c)]];
    if(ok(r - 1, c) && step[1][getid(r - 1, c)] == -1){
        step[1][getid(r - 1, c)] = s + 1;
        dfs1(r - 1, c, s + 1);
    }
    if(ok(r, c - 1) && step[1][getid(r, c -1)] == -1){
        step[1][getid(r, c -1)] = s + 1;
        dfs1(r, c - 1, s + 1);
    }
}

int main(){
    init();
    scanf("%d%d", &n, &m);
    int p = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%s", &s[p]);
        p += m;
    }
//    cout << s << endl;
    dfs0(1, 1, 0);
    if(step[0][getid(n, m)] == -1){
        printf("0\n");
    }else{
        dfs1(n, m, 0);
        int ans = 2;
        for(int i = 1; i <= n + m -3; ++i){
            if(cnt[i] == 1){
                ans = 1;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
5 4
....
.##.
...#
....
....
*/
