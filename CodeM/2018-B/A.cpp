#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<ctime>
using namespace std;
const int MAXN=505;
int ans[MAXN][MAXN];
int num[MAXN][MAXN];
int n,m,k;

struct Node{
    int x,y,z;
    int h,m,s1,s2;
}s[100005];

bool cmp(const Node &u,const Node &v){
    if(u.h==v.h&&u.m==v.m&&u.s1==v.s1){
        return u.s2<v.s2;
    }else if(u.h==v.h&&u.m==v.m){
        return u.s1<v.s1;
    }else if(u.h==v.h){
        return u.m<v.m;
    }else return u.h<v.h;
}

void getcopy(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(num[i][j]>=1) ans[i][j]=1;
            else ans[i][j]=0;
        }
    }
}

int main(){

    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(int i=1;i<=k;i++){
            scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].z);
            scanf("%d:%d:%d.%d",&s[i].h,&s[i].m,&s[i].s1,&s[i].s2);
        }
        sort(s+1,s+k+1,cmp);
        int ma=-1;
        int cnt=0;
        memset(num,0,sizeof(num));
        int x,y;
        for(int i=1;i<=k;i++){
            x=s[i].x;y=s[i].y;
            if(s[i].z==0){//进入
                if(num[x][y]==0){
                    cnt++;
                    num[x][y]=1;
                }else num[x][y]++;
            }else{//离开
                if(num[x][y]==1){
                    cnt--;
                    num[x][y]=0;
                }else num[x][y]--;
            }
            if(ma<=cnt){
                ma=cnt;
                getcopy();
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
