 import java.io.*;
 import java.lang.reflect.Array;
 import java.util.*;

public class Main {
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

    private static int MOD = (int) (1e9 + 7);
    private static int n;
    private static Tree g = new Tree();

    private static void init(int n){
        g.init(n);
    }

    static int log_base(int n, int base){
        return (int) (Math.log(n) / Math.log(base));
    }

    static long solve(Tree g){
        g.bfs(1);
        long sum = 0;
        int u, v;
        for(int i = 1; i <= n/2; ++i){
            for(int j = 2; i * j <= n; ++j){
                u = i;
                v = i * j;
                sum += g.d[u] + g.d[v] - 2 * g.d[g.lca(u, v)] + 1;
            }
        }
        return sum;
    }

    private static void preTest(int n){
        long sum = 0;
        for(int i = 1; i <= n/2; ++i){
            sum += n / i - 1;
        }
        System.out.println("ans: " + sum);
    }

    public static void main(String[] args) throws IOException {
//        preTest(200000);

        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            n = sc.nextInt();
            init(n);
            int u, v;
            for(int i = 1; i <= n - 1; ++i){
                u = sc.nextInt();
                v = sc.nextInt();
                g.addEdge(u, v);
            }
            System.out.print(solve(g));
        }
    }
}
/*
10
3 4
3 7
1 4
4 6
1 10
8 10
2 8
1 5
4 9
*/