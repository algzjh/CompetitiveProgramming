#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<bitset>
#include<ctime>
using namespace std;
const int MAXN=20005;
char s[MAXN];

int main(){
    while(scanf("%s",s)!=EOF){
        int len=strlen(s);
        if(len==1){
            if(s[0]=='0') printf("0\n");
            else printf("1\n");
            continue;
        }
        bool flag=false;
        for(int i=0;i<len;i++){
            if(s[i]=='0')  flag=true;
        }
        int ans=(len-1)*(len)/2;
        int p=-1;
        for(int i=1;i<=len-1;i++){
            if(s[i]=='1'){
                p=i;
                break;
            }
        }
        if(p!=-1){
            bool allone=true;
            for(int i=p;i<=len-1;i++){
                if(s[i]=='0') allone=false;
            }
            if(allone) ans+=(len-p);
            else ans+=(len-(p+1));
        }
        //if(!flag) ans++;
        printf("%d\n",ans);
    }
    return 0;
}


/*
10101000001

0: 0
1: 1
//特判
10: 1
11: 2

100: 3

101: 4
110: 4

111: 5

1000: 6

1001: 7
1010: 7

1011: 8
1100: 8
1101: 8
1110: 8

1111: 9

10000: 10

10001: 11
10010: 11

10011: 12
10100: 12
10101: 12
10110: 12

10111: 13
11000: 13
11001: 13
11010: 13
11011: 13
11100: 13
11101: 13
11110: 13

11111: 14

100000: 15

100001: 16
100010: 16

100011: 17
100100: 17
100101: 17
100110: 17

100111: 18
101000: 18
101001: 18
101010: 18
101011: 18
101100: 18
101101: 18
101110: 18

101111: 19
110000: 19
110001: 19
110010: 19
110011: 19
110100: 19
110101: 19
110110: 19
110111: 19
111000: 19
111001: 19
111010: 19
111011: 19
111100: 19
111101: 19
111110: 19

111111: 20

1000000: 21
*/
