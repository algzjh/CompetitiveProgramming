#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e2+5;
typedef long long LL;
char s[MAXN], ans[MAXN];

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        scanf("%s", s + 1);
        int cnt = 1, len = strlen(s + 1);
        for(int i = 1; i <= len; i+=2){
            ans[cnt++] = s[i];
        }
        ans[cnt++] = s[len];
        ans[cnt] = '\0';
        printf("%s\n", ans + 1);
    }
    return 0;
}
/*

*/
