# include <bits/stdc++.h>
# define fi first
# define se second
# define mk make_pair
using namespace std;
typedef long long LL;
const int MAXN = 1e2 + 5;
const int MAXM = 5e3 + 5;
const int MOD = 1e9 + 7;
const LL INF = 1e18;
typedef long long LL;
typedef pair<double, int> PDI;
char s[MAXN];

bool checkPalindrome(int l, int r){
    while(l <= r){
        if(s[l] != s[r])  return false;
        ++l;
        --r;
    }
    return true;
}

int main(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    bool flag = true;
    flag &= checkPalindrome(1, n);
    flag &= checkPalindrome(1, (n-1)/2);
    flag &= checkPalindrome((n+3)/2, n);
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}
