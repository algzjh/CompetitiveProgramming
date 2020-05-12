import java.util.*;


public class Main {
    static class Server {
        long a;
        int l, id;

        public Server(long _a, int _l, int _id) {
            a = _a;
            l = _l;
            id = _id;
        }
    }

    static class Servercomparator implements Comparator<Server> {
        @Override
        public int compare(Server server, Server t1) {
            if (server.a == t1.a)  return server.l > t1.l ? -1 : 1;
            return server.a > t1.a ? -1 : 1;
        }
    }

    private static void init(){
        servers.clear();
        zero_list.clear();
        one_list.clear();
        ans_list.clear();
        low_voltage_cnt = 0;
    }

    static final int MAXN = (int) (2e3 + 5);
    static ArrayList<Server> servers = new ArrayList<>();
    static ArrayList<Server> zero_list = new ArrayList<>();
    static ArrayList<Server> one_list = new ArrayList<>();
    static ArrayList<Server> ans_list = new ArrayList<>();
    static int low_voltage_cnt;

    public static void main(String[] args) {
        ArrayList<Integer> temp = new ArrayList<>();
        Collections.reverse(temp);

        Scanner sc = new Scanner(System.in);
        int n;
        long m;
        n = sc.nextInt();
        m = sc.nextLong();
        init();
        for (int i = 1; i <= n; ++i) {
            Server server = new Server(sc.nextLong(), sc.nextInt(), i);
            servers.add(server);
        }
        Collections.sort(servers, new Servercomparator());
        long sum = 0;

        for (Server s : servers) {
//            System.out.println(s.a + " " + s.l);
            if (sum < m) {
                sum += s.a;
                if(s.l == 0) {
                    zero_list.add(s);
                }else{
                    ans_list.add(s);
                    low_voltage_cnt += 1;
                }
            }else{
                if(s.l == 1){
                    one_list.add(s);
                }
            }
        }
        long margin = sum - m;
        Collections.reverse(zero_list);
        int p = 0;
        for(int i = 0; i < zero_list.size(); ++i){
            if(p < one_list.size()){
                long reduce = zero_list.get(i).a - one_list.get(p).a;
                if(margin >= reduce){
                    margin -= reduce;
                    ans_list.add(one_list.get(p));
                    ++low_voltage_cnt;
                    ++p;
                }else{
                    ans_list.add(zero_list.get(i));
                }
            }else{
                ans_list.add(zero_list.get(i));
            }
        }

        System.out.println(ans_list.size() + " " + low_voltage_cnt);
        for(int i = 0; i < ans_list.size(); ++i){
            System.out.print(String.format("%d%c", ans_list.get(i).id, i == ans_list.size() - 1 ? '\n' : ' '));
        }
    }
}
/*
4 10
3 1
7 0
5 1
4 1
 */