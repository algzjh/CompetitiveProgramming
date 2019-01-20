#include<bits/stdc++.h>
using namespace std;
const int MAXN = 205;  //X 集合中的顶点数上限
const int MAXM = 405;  // 总的边数上限
const int INF = 0x3f3f3f3f;
int head[MAXN],tot;
int S,T;  // S 是源点，T 是汇点
int d[MAXN];  // 存储每个顶点的层次

struct Edge{
    int v,c,nxt;
    // v 是指边的另一个顶点，c 表示容量
}e[MAXM];

void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}

void addedge(int u,int v,int c){
    // 插入一条从 u 连向 v，容量为 c 的弧
    e[tot].v=v;e[tot].c=c;
    e[tot].nxt=head[u];
    head[u]=tot++;
}

bool bfs(){
    // bfs构建层次图G_L
    memset(d,-1,sizeof(d));
    queue<int> q;
    q.push(S);
    d[S]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].nxt){
            int v=e[i].v;
            if(e[i].c>0&&d[v]==-1){
                q.push(v);
                d[v]=d[u]+1;
            }
        }
    }
    return (d[T]!=-1);
}

int dfs(int u,int flow){
    // dfs在层次图G_L中寻找增广路径
    // flow 表示当前搜索分支的流量上限
    if(u==T){
        return flow;
    }
    int res=0;
    for(int i=head[u];i!=-1;i=e[i].nxt){
        int v=e[i].v;
        if(e[i].c>0&&d[u]+1==d[v]){
            int tmp=dfs(v,min(flow,e[i].c));
            // 递归计算顶点 v，用 c(u, v) 来更新当前流量上限
            flow-=tmp;
            e[i].c-=tmp;
            res+=tmp;
            e[i^1].c+=tmp;  // 修改反向弧的容量
            if(flow==0){  // 流量达到上限，不必继续搜索了
                break;
            }
        }
    }
    if(res==0){
        // 当前没有经过顶点 u 的可行流，不再搜索顶点 u
        d[u]=-1;
    }
    return res;
}

int maxflow(){  // 函数返回值就是最大流的结果
    int res=0;
    while(bfs()){
        res+=dfs(S,INF);  // 初始流量上限为 INF
    }
    return res;
}

int main(){
    int m,n;
    while(~scanf("%d%d",&m,&n)){
        init();
        S=1;T=n;
        int u,v,c;
        for(int i=1;i<=m;++i){
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
            addedge(v,u,0);
        }
        printf("%d\n",maxflow());
    }
    return 0;
}