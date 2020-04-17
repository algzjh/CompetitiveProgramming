#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e3 + 5;
char s[MAXN];
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        for(int i = 0; i < b; ++i){
            s[i] = char('a' + i);
        }
        for(int i = b; i < a; ++i){
            s[i] = s[i-1];
        }
        for(int i = a; i < n; ++i){
            s[i] = s[i%a];
        }
        s[n] = '\0';
        printf("%s\n", s);
    }
    return 0;
}
