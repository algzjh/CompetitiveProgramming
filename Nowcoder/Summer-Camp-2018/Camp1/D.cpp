#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int MA[10][10],MB[10][10],MC[10][10];
vector<int> v;
int rv[10];
map<PII,int> edgeid;
set<int> s;

int main(){
    int n,m1,m2;
    while(~scanf("%d%d%d",&n,&m1,&m2)){
        memset(MA,0,sizeof(MA));
        memset(MB,0,sizeof(MB));
        memset(rv,0,sizeof(rv));
        edgeid.clear();
        s.clear();
        int uu,vv;
        for(int i=1;i<=m1;i++){
            scanf("%d%d",&uu,&vv);
            uu-=1;vv-=1;
            MA[uu][vv]=1;MA[vv][uu]=1;
        }
        for(int i=1;i<=m2;i++){
            scanf("%d%d",&uu,&vv);
            uu-=1;vv-=1;
            MB[uu][vv]=1;MB[vv][uu]=1;
            edgeid[PII(uu,vv)]=i;
            edgeid[PII(vv,uu)]=i;
        }
        v.clear();
        for(int i=0;i<n;i++) v.push_back(i);
        bool flag;
        int ans = 0;
        do{
            int stat=0;
            for(int i=0;i<n;i++) rv[v[i]]=i;
            memset(MC,0,sizeof(MC));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    MC[v[i]][v[j]]=MB[i][j];
                }
            }
            flag = true;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(MA[i][j]==1&&(MC[i][j]!=1)){
                        flag=false;
                        break;
                    }
                    if(MA[i][j]==0&&MC[i][j]==1){
                       int id = edgeid[PII(rv[i],rv[j])];
                       stat |= (1<<id);
                    }
                }
                if(!flag) break;
            }
            if(flag) s.insert(stat);

        }while(next_permutation(v.begin(),v.end()));
        printf("%d\n",s.size());
    }
    return 0;
}
/*
6 2 2
1 2
1 3
6 5
4 5

6 2 2
1 2
1 3
4 5
5 6
*/