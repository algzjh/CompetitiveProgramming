#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e3 + 5;
const int MAXM = 1e4 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

struct Node{
    int a, b;
}s[MAXN];


bool isRight(const Node& u, const Node& v){
    return v.a >= u.b;
}

bool isPoint(const Node& u){
    return u.a == u.b;
}

bool canJumpByTwo(int a, int b){
    int len = abs(a - b);
    return len%2 == 0;
}

int calcEd(int st, const Node& u, int dir1, int dir2){
    if(isPoint(u))  return u.a;
    if(dir1 == dir2){
        if(dir1){
            if(canJumpByTwo(st, u.b))  return u.b;
            else return u.b - 1;
        }else{
            if(canJumpByTwo(st, u.a))  return u.a;
            else return u.a + 1;
        }
    }else{
        if(dir1) return u.a;
        else return u.b;
    }
}

int calcStep(int st, int ed){
    if(st == ed)  return 0;
    int len = abs(ed - st) ;
    return int(ceil(len/2.0));
}

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        bool first = true;
        int m = 0, ta, tb;
        for(int i = 1; i <= n; ++i){
            if(first){
                ++m;
                first = false;
                scanf("%d%d", &s[m].a, &s[m].b);
            }else{
                scanf("%d%d", &ta, &tb);
                if(ta >= s[m].b || tb <= s[m].a){
                    ++m;
                    s[m].a = ta, s[m].b = tb;
                }else{
                    s[m].a = max(s[m].a, ta);
                    s[m].b = min(s[m].b, tb);
                }
            }
        }
        if(n == 1){
            printf("0\n");
            continue;
        }
        int st = 0, ans = 0, ed;
        if(isRight(s[1], s[2])) st = s[1].b;
        else st = s[1].a;
        for(int i = 2; i <= m; ++i){
            if(i == m){
                if(s[i].a >= st){
                    ans += calcStep(st, s[i].a);
                }else{
                    ans += calcStep(st, s[i].b);
                }
            }else{
                ed = calcEd(st, s[i], isRight(s[i-1], s[i]), isRight(s[i], s[i+1]));
                ans += calcStep(st, ed);
                st = ed;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


/*
100
1
1 1000000
2
1 1
1 1
3
1 10
1 10
10 100
3
1 2
2 3
3 4
3
1 2
2 3
4 6
*/
