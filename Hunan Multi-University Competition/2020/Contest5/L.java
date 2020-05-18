import java.io.*;
import java.util.*;


public class Main {
    private static int MAXN = (int) (1e3 + 5);
    static class Grid{
        int v, up, down, left, right;
    }

    private static Grid[][] g = new Grid[MAXN][MAXN];

    private static void init(int r, int c){
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                g[i][j] = new Grid();
            }
        }
        for(int j = 1; j <= c; ++j){
            g[1][j].up = g[r][j].down = -1;
        }
        for(int i = 1; i <= r; ++i){
            g[i][1].left = g[i][c].right = -1;
        }
    }

    public static void main(String[] args) throws IOException {
        File file = new File("lucky.in");
        BufferedWriter writer = new BufferedWriter(new FileWriter("lucky.out"));
        Scanner sc = new Scanner(file);
        int r, c;
        r = sc.nextInt();
        c = sc.nextInt();
        init(r, c);
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                g[i][j].v = sc.nextInt();
                if(i > 1){
                    g[i][j].up = Math.max(g[i-1][j].v, g[i-1][j].up);
                }
                if(j > 1){
                    g[i][j].left = Math.max(g[i][j-1].v, g[i][j-1].left);
                }
            }
        }
        for(int i = r; i >= 1; --i){
            for(int j = c; j >= 1; --j){
                if(i < r){
                    g[i][j].down = Math.max(g[i+1][j].v, g[i+1][j].down);
                }
                if(j < c){
                    g[i][j].right = Math.max(g[i][j + 1].v, g[i][j + 1].right);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                if(g[i][j].v > g[i][j].up)  ++ans;
                if(g[i][j].v > g[i][j].down)  ++ans;
                if(g[i][j].v > g[i][j].left)  ++ans;
                if(g[i][j].v > g[i][j].right)  ++ans;
            }
        }
        writer.write(String.format("%d", ans));
//        writer.write(String.valueOf(ans));
        writer.close();
    }
}
/*

*/