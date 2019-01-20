#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXM = 10000;
const int INF = 0x3f3f3f3f;

struct Edge{
    int v,c,w,nxt;
    // v ��ʾ�ߵ���һ�����㣬
    // c ��ʾ��ǰʣ��������
    // w ��ʾ��λ��������
}e[MAXM];

int head[MAXN],s,t,tot;
// s ��ʾԴ�㣬t ��ʾ��㣬��Ҫ�ڽ��� costflow ֮ǰ�������

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
    // ������С���������
    int ret=0;  // �ۼӺ�
    while(spfa()){
        int flow=INF;
        for(int i=t;i!=s;i=e[pre[i]^1].v){
            flow=min(e[pre[i]].c,flow);
            // ���㵱ǰ����·�ϵ���С����
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