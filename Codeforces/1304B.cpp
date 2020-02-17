#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
string s[MAXN], ans, t, rt;
map<string, int> mp;
 
 
bool checkSame(string s){
    int n = s.length();
    for(int i = 1; i < n; ++i){
        if(s[i] != s[0])  return false;
    }
    return true;
}
 
bool checkPalindrome(string s){
    int n = s.length();
    int L = 0, R = n - 1;
    while(L < R){
        if(s[L] != s[R])  return false;
        ++L;
        --R;
    }
    return true;
}
 
void init(){
    ans = "";
    mp.clear();
}
 
int main(){
    int n, m;
    cin >> n >> m;
    init();
    bool useSameOrPalin = false;
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        mp[s[i]] = i;
        if(not useSameOrPalin){
            if(checkSame(s[i]) or checkPalindrome(s[i])){
                ans = s[i];
                mp[s[i]] = 0;
                useSameOrPalin = true;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(mp[s[i]]){
            t = rt = s[i];
            reverse(rt.begin(), rt.end());
            if(mp[rt] != 0 and mp[rt] != mp[s[i]]){
                ans = t + ans;
                ans = ans + rt;
                mp[t] = 0;
                mp[rt] = 0;
            }
        }
    }
    cout << ans.length() << endl;
    cout << ans << endl;
    return 0;
}
