/**
 * greedy, math, 900
 * CF1445-B
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e2+5;
typedef long long LL;

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", max(a + b, c + d));
    }
    return 0;
}
/*
1: (a,c)
2: (a,c)
...
100: (a,b)
or:  (d,c)
*/