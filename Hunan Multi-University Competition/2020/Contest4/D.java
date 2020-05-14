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

    static class ServerComparator implements Comparator<Server> {
        @Override
        public int compare(Server lhs, Server rhs) {
            if(lhs.a == rhs.a){
                if(lhs.l > rhs.l)  return -1;
                else if(lhs.l < rhs.l)  return 1;
                return 0;
            }
            return  lhs.a > rhs.a ? -1 : 1;
        }
    }

    private static void init(){
        servers.clear();
        zero_stack.clear();
        ans_list.clear();
        low_voltage_cnt = 0;
    }

    static ArrayList<Server> servers = new ArrayList<>();
    static Stack<Server> zero_stack = new Stack<>();
    static ArrayList<Integer> ans_list = new ArrayList<>();
    static int low_voltage_cnt;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n, m;
        n = sc.nextLong();
        m = sc.nextLong();
        init();

        for (int i = 1; i <= n; ++i) {
            Server server = new Server(sc.nextLong(), sc.nextInt(), i);
            servers.add(server);
        }
        Collections.sort(servers, new ServerComparator());

        long sum = 0;

        for (Server s : servers) {
            if (sum < m) {
                sum += s.a;
                if(s.l == 0) {
                    zero_stack.push(s);
                }else{
                    ans_list.add(s.id);
                    ++low_voltage_cnt;
                }
            }else{
                if(zero_stack.empty())  break;
                if(s.l == 1){
                    if(sum - zero_stack.peek().a + s.a >= m){
                        sum = sum - zero_stack.peek().a + s.a;
                        ans_list.add(s.id);
                        zero_stack.pop();
                        ++low_voltage_cnt;
                    }
                }
            }
        }

        while(!zero_stack.empty()){
            ans_list.add(zero_stack.peek().id);
            zero_stack.pop();
        }

        System.out.println(ans_list.size() + " " + low_voltage_cnt);
        for(int i = 0; i < ans_list.size(); ++i){
            System.out.print(ans_list.get(i));
            if(i == ans_list.size() - 1){
                System.out.print("\n");
            }else{
                System.out.print(" ");
            }
        }
    }
}
/*
4 10
3 1
4 1
2 1
1 1
 */