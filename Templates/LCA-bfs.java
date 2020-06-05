static class Tree{
    static final int MAXN = (int) (2e5 + 5);
    static final int LOG = 20;
    static ArrayList<ArrayList<Integer> > adj;
    static int[][] f = new int[MAXN][LOG + 2];
    static int[] d = new int[MAXN];

    static void addEdge(int u, int v){
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    static void init(int n){
        adj = new ArrayList<>();
        for(int i = 0; i <= n; ++i){
            adj.add(new ArrayList<>());
            d[i] = 0;
            Arrays.fill(f[i], 0);
        }
    }

    void bfs(int r){
        Queue<Integer> q = new LinkedList<>();
        q.add(r);
        d[r] = 1;
        while(! q.isEmpty()){
            int u = q.peek();
            q.poll();
            for(int v : adj.get(u)){
                if(d[v] > 0)  continue;
                d[v] = d[u] + 1;
                f[v][0] = u;
                for(int j = 1; j <= LOG; ++j){
                    f[v][j] = f[f[v][j-1]][j-1];
                }
                q.add(v);
            }
        }
    }

    int lca(int u, int v){
        if(d[u] > d[v]){
            int t = u;
            u = v;
            v = t;
        }
        for(int i = LOG; i >= 0; --i){
            if(d[f[v][i]] >= d[u])  v = f[v][i];
        }
        if(u == v)  return u;
        for(int i = LOG; i >= 0; --i){
            if(f[u][i] != f[v][i]){
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    }
}