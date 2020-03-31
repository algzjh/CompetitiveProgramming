#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char s[MAXN];
int cntL, cntR, cntU, cntD;


int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        cntL = cntR = cntU = cntD = 0;
        for(int i = 1; i <= n; ++i){
            if(s[i] == 'L')  ++cntL;
            else if(s[i] == 'R')  ++cntR;
            else if(s[i] == 'U')  ++cntU;
            else ++cntD;
        }
        if(cntD == 0 or cntU == 0){
            cntL = min(1, cntL);
            cntR = min(1, cntR);
        }
        if(cntL == 0 or cntR == 0){
            cntD = min(1, cntD);
            cntU = min(1, cntU);
        }
        printf("%d\n", 2 * min(cntL, cntR) + 2 * min(cntU, cntD));
        for(int i = 1; i <= min(cntL, cntR); ++i)  printf("R");
        for(int i = 1; i <= min(cntU, cntD); ++i)  printf("D");
        for(int i = 1; i <= min(cntL, cntR); ++i)  printf("L");
        for(int i = 1; i <= min(cntU, cntD); ++i)  printf("U");
        printf("\n");

    }
    return 0;
}
