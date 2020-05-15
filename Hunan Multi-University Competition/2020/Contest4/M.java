import java.util.*;


public class Main {
    static class Position{
        int r, c;
        public Position(int _r, int _c){
            r = _r;
            c = _c;
        }
    }

    static class Code{
        char ch;
        Position p;
        int pre;
        public Code(char _ch, Position _p, int _pre){
            ch = _ch;
            p = _p;
            pre = _pre;
        }
    }

    static HashMap<Character, Integer> last_position = new HashMap<>();
    static ArrayList<Code> codes = new ArrayList<>();


    static private void init(){
        codes.clear();
        last_position.clear();
        for(char c = 'a'; c <= 'z'; ++c){
            last_position.put(c, -1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = Integer.parseInt(sc.nextLine());

        init();
        for(int i = 1; i <= n; ++i){
            String line = sc.nextLine();
            for(int j = 0; j < line.length(); ++j){
                char ch = line.charAt(j);
                Position p = new Position(i, j + 1);
                Code code = new Code(ch, p, -1);

                if(ch == '{'){
                    last_position.put(ch, codes.size());
                    codes.add(code);
                }else if(ch == '}'){
                    int pos = 0;
                    for(int k = codes.size() - 1; k >= 0; --k){
                        if(codes.get(k).ch == '{'){
                            pos = k;
                            break;
                        }else if('a' <= codes.get(k).ch && codes.get(k).ch <= 'z'){
                            last_position.put(codes.get(k).ch, codes.get(k).pre);
                        }
                    }
                    codes.subList(pos, codes.size()).clear();
//                    codes.removeRange(pos, codes.size());
                }else if('a' <= ch && ch <= 'z'){
                    if(last_position.get(ch) != -1){
                        int lp = last_position.get(ch);
                        code.pre = lp;
                        System.out.format("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",
                                p.r, p.c, ch, codes.get(lp).p.r, codes.get(lp).p.c);
                        last_position.put(ch, codes.size());
                        codes.add(code);
                    }else{
                        last_position.put(ch, codes.size());
                        codes.add(code);
                    }
                }
            }
        }

    }
}
/*

*/