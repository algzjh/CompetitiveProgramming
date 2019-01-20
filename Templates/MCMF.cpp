#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXM = 10000;
const int INF = 0x3f3f3f3f;

struct Edge{
    int v,c,w,nxt;
    // v 表示边的另一个顶点，
    // c 表示当前剩余容量，
    // w 表示单位流量费用
}e[MAXM];

int head[MAXN],s,t,tot;
// s 表示源点，t 表示汇点，需要在进行 costflow 之前设置完毕

void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}

void addedge(int u,int v,int c,int w){
    e[tot].v=v;e[tot].c=c;e[tot].w=w;
    e[tot].nxt=head[u];
    head[u]=tot++;
}

bool vis[MAXN];
int d[MAXN];
int pre[MAXN];

bool spfa(){
    memset(vis,0,sizeof(vis));
    memset(d,0x3f,sizeof(d));
    memset(pre,-1,sizeof(pre));
    d[s]=0;
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=e[i].nxt){
            if(e[i].c){
                int v=e[i].v;
                if(d[u]+e[i].w<d[v]){
                    d[v]=d[u]+e[i].w;
                    pre[v]=i;
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                }
            }
        }
    }
    return (pre[t]!=-1);
}

int costflow(){
    // 计算最小费用最大流
    int ret=0;  // 累加和
    while(spfa()){
        int flow=INF;
        for(int i=t;i!=s;i=e[pre[i]^1].v){
            flow=min(e[pre[i]].c,flow);
            // 计算当前增广路上的最小流量
        }
        for(int i=t;i!=s;i=e[pre[i]^1].v){
            e[pre[i]].c-=flow;
            e[pre[i]^1].c+=flow;
            ret+=e[pre[i]].w*flow;
        }
    }
    return ret;
}

int main(){

    return 0;
}