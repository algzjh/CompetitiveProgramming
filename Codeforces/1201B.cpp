#include <bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 5;
const int MAXM = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
int a[MAXN];
multiset<int> s;
 
int main(){
    s.clear();
    int n;
    scanf("%d", &n);
    LL sum = 0;
    for(int i = 1;i <= n; ++i){
        scanf("%d", &a[i]);
        sum += a[i];
        s.insert(a[i]);
    }
//    cout << "sum: " << sum << endl;
    if(sum&1){
        printf("NO\n");
        return 0;
    }
 
//    for(auto it : s){
//        cout << it << " ";
//    }
//    cout << endl;
 
    bool flag = true;
//    cout << "size: " << s.size() << endl;
    while(!s.empty()){
        if(s.size()==1){
            flag = false;
            break;
        }else if(s.size()==2){
            auto it1 = s.begin();
            auto it2 = s.end();
            --it2;
            if((*it1) != (*it2)){
                flag = false;
                break;
            }else{
                s.erase(it1);
                s.erase(it2);
            }
        }else{
            auto it1 = s.begin();
            auto it2 = s.end();
            --it2; --it2;
            auto it3 = s.end();
            --it3;
            int t1 = *it1, t2 = *it2, t3 = *it3;
//            cout << "t1: " << t1 << " t2: " << t2 << " t3: " << t3 << endl;
            if((t3-t2)>=t1){
                s.erase(it1);
                s.erase(it3);
                if(t3-t1 != 0) s.insert(t3-t1);
            }else{
                s.erase(it1);
                s.erase(it2);
                s.erase(it3);
                t1 -= (t3-t2);
                t3 = t2;
                if(t1&1){
                    if(t3 - (t1-1)/2 -1 != 0)s.insert(t3 - (t1-1)/2 -1);
                    if(t3 - (t1-1)/2 != 0)  s.insert(t3 - (t1-1)/2);
//                    if((t3-t2)-((t3-1)/2)-1 != 0) s.insert((t3-t2)-((t3-1)/2)-1);
//                    if((t3-t2)-((t3-1)/2) != 0)  s.insert((t3-t2)-((t3-1)/2));
                }else{
                    if(t3 - t1/2 != 0){
                        s.insert(t3 - t1/2);
                        s.insert(t3 - t1/2);
//                        s.insert((t3-t2)-(t3/2));
//                        s.insert((t3-t2)-(t3/2));
                    }
                }
            }
        }
 
//        int L = *(s.begin());
//        auto it1 = s.begin();
//        auto it2 = s.end();
//        auto it3 = s.end();
//        --it3;
//        --it3;
//        --it2;
//        int R = *(it2);
//        cout << "L: " << L << " R: " << R << endl;
//        R-=L;
//        if(R>0){
//            s.erase(it1);
//            //s.erase((s.rbegin()+1).base());
//            s.erase(it2);
//            s.insert(R);
//        }else{
//            s.erase(it1);
//            s.erase(it2);
//        }
    }
    printf("%s\n",flag?"YES":"NO");
    return 0;
}
/*
10
34 24 21 42 80 2 4 200 32 1
 
5
2 3 1 100 100
*/
