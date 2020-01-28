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
int cnta, cntb;

struct Problem{
    int kind, deadline;
}p[MAXN];

bool cmp(const Problem &u, const Problem &v){
    if(u.deadline == v.deadline)  return u.kind < v.kind;
    return u.deadline < v.deadline;
}

void init(){
    cnta = 0, cntb = 0;
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n, T, a, b;
        scanf("%d%d%d%d", &n, &T, &a, &b);
        init();
        for(int i = 1; i <= n; ++i){
            scanf("%d", &p[i].kind);
            if(p[i].kind == 0)  ++cnta;
            else  ++cntb;
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &p[i].deadline);
        }
        p[n+1].kind = 0;
        p[n+1].deadline = T + 1;
        sort(p + 1, p + n + 2, cmp);
        int x = 0, y = 0, ans = 0, cana, canb;
        LL need, has;
        for(int i = 1; i <= n + 1; ++i){
            need = 1LL * x * a + 1LL * y * b;
            has = p[i].deadline - 1 - need;
            if(has >= 0){
                cana = min(1LL * (cnta - x), has/a);
                has -= cana * a;
                canb = min(1LL * (cntb - y), has/b);
                ans = max(ans, x + y + cana + canb);
            }
            int pos = i;
            while(pos <= n + 1 and p[pos].deadline == p[i].deadline){
                if(p[pos].kind == 0)  ++x;
                else ++y;
                ++pos;
            }
            i = pos - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
3 5 1 3

1 1 3
0 0 1
2 1 4
3

2 5 2 3
3 2
1 0
3 2
2

1 20 2 4
2
0
16
1

6 20 2 5
5 5 2 5 2 2
1 1 0 1 0 0
0 8 2 9 11 6
0

4 16 3 6
6 3 6 6
1 0 1 1
8 3 5 6
1

6 20 3 6
3  6  3 3  6  3
0  1  0 0  1  0
20 11 3 20 16 17
4

set1(problem)
set2(problem)

x * a + y * b < min(set2.tim)
x * a + y * b < T;

6 17 2 6
2 2 6 2 2  6
0 0 1 0 0  1
7 6 3 7 10 12
*/
