#include<bits/stdc++.h>
using namespace std;
const int MAXN = 205;  //X �����еĶ���������
const int MAXM = 405;  // �ܵı�������
const int INF = 0x3f3f3f3f;
int head[MAXN],tot;
int S,T;  // S ��Դ�㣬T �ǻ��
int d[MAXN];  // �洢ÿ������Ĳ��

struct Edge{
    int v,c,nxt;
    // v ��ָ�ߵ���һ�����㣬c ��ʾ����
}e[MAXM];

void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}

void addedge(int u,int v,int c){
    // ����һ���� u ���� v������Ϊ c �Ļ�
    e[tot].v=v;e[tot].c=c;
    e[tot].nxt=head[u];
    head[u]=tot++;
}

bool bfs(){
    // bfs�������ͼG_L
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
    // dfs�ڲ��ͼG_L��Ѱ������·��
    // flow ��ʾ��ǰ������֧����������
    if(u==T){
        return flow;
    }
    int res=0;
    for(int i=head[u];i!=-1;i=e[i].nxt){
        int v=e[i].v;
        if(e[i].c>0&&d[u]+1==d[v]){
            int tmp=dfs(v,min(flow,e[i].c));
            // �ݹ���㶥�� v���� c(u, v) �����µ�ǰ��������
            flow-=tmp;
            e[i].c-=tmp;
            res+=tmp;
            e[i^1].c+=tmp;  // �޸ķ��򻡵�����
            if(flow==0){  // �����ﵽ���ޣ����ؼ���������
                break;
            }
        }
    }
    if(res==0){
        // ��ǰû�о������� u �Ŀ������������������� u
        d[u]=-1;
    }
    return res;
}

int maxflow(){  // ��������ֵ����������Ľ��
    int res=0;
    while(bfs()){
        res+=dfs(S,INF);  // ��ʼ��������Ϊ INF
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