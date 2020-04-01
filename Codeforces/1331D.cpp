#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e3 + 5;
const int MOD = 998244353;
char s[10];
 
int main() {
    scanf("%s", s + 1);
    int p = int(s[7] - '0');
    if(p&1)  printf("1\n");
    else printf("0\n");
    return 0;
}
/*
170362930
0
168335702
0
 
168335703
1
6043162371
1
 
*/
