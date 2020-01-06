#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(2e3 + 5);
const int MAXM = static_cast<const int>(2e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
map<string, int> mp;
string s[MAXN];
char candidate[3] = {'S', 'E', 'T'};

void init(){
    mp.clear();
}

int main(){
    int n, k;
    cin >> n >> k;
    init();
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        if(mp.find(s[i]) == mp.end())  mp[s[i]] = 1;
        else ++mp[s[i]];
    }
    int ans = 0;
    string tmp;
//    for(auto it : mp){
//        cout << it.fi << " " << it.se << endl;
//    }
    for(int i = 1; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            tmp = "";
            for(int r = 0; r < k; ++r){
                if(s[i][r] == s[j][r])  tmp += s[i][r];
                else{
                    for(int g = 0; g < 3; ++g){
                        if(candidate[g] != s[i][r] &&
                           candidate[g] != s[j][r]){
                            tmp += candidate[g];
                            break;
                        }
                    }
                }
            }
//            cout << s[i] << " " << s[j] << " " << tmp << endl;
            if(mp.find(tmp) != mp.end())  ans += mp[tmp];
        }
    }
    cout << ans/3 << endl;
    return 0;
}
