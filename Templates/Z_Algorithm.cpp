/*
 * Z algorithm
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(5e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int n;
char s[MAXN];
int z[MAXN];

void get_z(){
    int l = 0, r = 0;
    for(int i = 1; i < n; ++i){
        if(i > r){
            l = i, r = i;
            while(r < n && s[r-l] == s[r])  ++r;
            z[i] = r - l;
            --r;
        }else{
            int k = i - l;
            if(z[k] < r - i + 1)  z[i] = z[k];
            else{
                l = i;
                while(r < n && s[r - l] == s[r]) ++r;
                z[i] = r - l;
                --r;
            }
        }
    }
}

int main(){
    while(~scanf("%s", s)){
        n = strlen(s);
        get_z();
        for(int i = 0; i < n; ++i){
            printf("%d ",z[i]);
        }
        printf("\n");
    }
    return 0;
}
/*

*/
