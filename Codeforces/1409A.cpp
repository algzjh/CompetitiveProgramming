#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e6+5;

int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int a, b;
        scanf("%d%d", &a, &b);
        int ans = abs(b - a) / 10;
        if( abs(b - a)%10 != 0){
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*

*/
