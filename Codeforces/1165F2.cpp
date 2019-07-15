#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2e5 + 5;
int k[MAXN];
vector<int> v[MAXN];
vector<PII> pv;
int n, m;
 
int calcPreFix(vector<int> &v, int day){
    return upper_bound(v.begin(), v.end(), day) - v.begin();
}
 
bool check(int d){
    int Res = 0, tmp;
    pv.clear();
    for(int i = 1; i <= n; ++i){
        if(k[i] == 0) continue;
        tmp = calcPreFix(v[i], d);
        if(tmp > 0){
            pv.emplace_back(mk(v[i][tmp - 1], i));
//            if(tmp >= k[i]){
//                pv.emplace_back(mk(v[i][tmp - 1], k[i]));
//            }else{
//                pv.emplace_back(mk(v[i][tmp - 1], tmp));
//                Res += k[i] - tmp;
//            }
        }else{
            Res += k[i];
        }
    }
    sort(pv.begin(), pv.end());
//    cout << "guess day: " << d << endl;
//    for(auto it : pv){
//        cout << it.fi << " " << it.se << endl;
//    }
    int preday = 0, nowday = 0, nowmoney = 0;
    for(auto it : pv){
        nowday = it.fi;
        if(nowday > preday){
            nowmoney += nowday - preday;
            preday = nowday;
        }
        if(nowmoney >= k[it.se]){
            nowmoney -= k[it.se];
        }else{
            Res += k[it.se] - nowmoney;
            nowmoney = 0;
        }
    }
    if(nowday < d){
        nowmoney += d - preday;
    }
    //cout << "Boolean: " << (nowmoney >= 2 * Res) << endl;
    return nowmoney >= 2 * Res;
}
 
void init(int n){
    for(int i = 1; i <= n; ++i){
        v[i].clear();
    }
}
 
int main(){
    int totk = 0;
    scanf("%d%d", &n, &m);
    init(n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &k[i]);
        totk += k[i];
    }
    int d, t;
    for(int i = 1; i <= m; ++i){
        scanf("%d%d", &d, &t);
        v[t].emplace_back(d);
    }
    for(int i = 1; i <= m; ++i){
        sort(v[i].begin(), v[i].end());
    }
    int L = 1, R = totk * 2, mid, ans = R;
    while(L <= R){
        mid = (L + R) / 2;
        if(check(mid)){
            ans = mid;
            R = mid - 1;
        }else{
            L = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
