#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 105;
const int MOD = 1e9+7;
typedef long long LL;
int a[MAXN];

int main() {
    int n;
    while(~scanf("%d", &n)){
        int pos = 0, neg = 0, zero = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(a[i] > 0)  ++pos;
            else if(a[i] < 0) ++neg;
            else ++zero;
        }
        if(pos >= ceil(n/2.0))  printf("1\n");
        else if(neg >= ceil(n/2.0))  printf("-1\n");
        else printf("0\n");
    }
    return 0;
}
/*
5
10 0 7 -2 -6
 */
