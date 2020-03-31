#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
const int MOD = 998244353;

struct Node{
    int x, y;
}p[3];


bool check(int in1, int in2, int out1, int out2){
    return out1 <= in1 and in2 <= out2;
}

int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int L, R, D, U;
        scanf("%d%d%d%d", &L, &R, &D, &U);
        for(int i = 0; i < 3; ++i){
            scanf("%d%d", &p[i].x, &p[i].y);
        }
        bool flag = true;
        if(L == R and L != 0){
            flag &= (check(p[0].x, p[0].x + 1, p[1].x, p[2].x) or
                     check(p[0].x - 1, p[0].x, p[1].x, p[2].x));
        }else if(L < R){
            flag &= check(p[0].x, p[0].x + (R - L), p[1].x, p[2].x);
        }else{
            flag &= check(p[0].x - (L - R), p[0].x, p[1].x, p[2].x);
        }

        if(flag){
            if(D == U and D != 0){
                flag &= (check(p[0].y, p[0].y + 1, p[1].y, p[2].y) or
                         check(p[0].y - 1, p[0].y, p[1].y, p[2].y));
            }else if(D < U){
                flag &= check(p[0].y, p[0].y + (U - D), p[1].y, p[2].y);
            }else{
                flag &= check(p[0].y - (D - U), p[0].y, p[1].y, p[2].y);
            }
        }

        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}
/*
6
0 0 0 1
0 0 0 0 0 1
*/
