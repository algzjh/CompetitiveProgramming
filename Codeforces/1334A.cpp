#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
 
 
struct Node{
    int p, c;
}s[MAXN];
 
 
int main() {
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &s[i].p, &s[i].c);
            if(not flag) continue;
            if(s[i].p < s[i].c){
                flag = false;
            }
            if(i >= 2){
                if(s[i].p < s[i-1].p or s[i].c < s[i-1].c or s[i].p - s[i-1].p < s[i].c - s[i-1].c){
                    flag = false;
                }
            }
        }
        printf("%s\n", flag ? "YES": "NO");
    }
    return 0;
}
