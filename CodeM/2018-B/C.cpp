//WA，还没AC
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
const int MAXN=1e3+5;
double eps=1e-6;
double PI = acos(-1.0);

long double dist(long double x1,long double y1,long double x2,long double y2){
    long double dx=x1-x2,dy=y1-y2;
    return sqrtl(dx*dx+dy*dy);
}

long double Min(long double a,long double b){
    return a<b?a:b;
}

int main(){
    long double r;
    while(cin>>r){
        long double x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
//        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        long double ans=dist(x1,y1,x2,y2);
        long double a=2.0*r*(x2-x1),b=2.0*r*(y2-y1);
        //cout<<a<<" "<<b<<endl;
        long double sita=atanl(b/a);
        //cout<<"sita: "<<sita*180.0/PI<<endl;
        //cout<<sin(sita)<<endl;
        long double x0=r*cosl(sita),y0=r*sinl(sita);
        long double sx0=r*cosl(sita+PI),sy0=r*sinl(sita+PI);
        //cout<<"x0: "<<x0<<" y0: "<<y0<<endl;
        //cout<<"sx0: "<<sx0<<" sy0: "<<sy0<<endl;
        long double mi=dist(x1,y1,x0,y0)+dist(x2,y2,sx0,sy0);
        mi=Min(mi,dist(x1,y1,sx0,sy0)+dist(x2,y2,x0,y0));
        long double tmp=x1*x1+x2*x2+y1*y1+y2*y2+2.0*r*r;
        mi=Min(mi,Min(a,-a)+tmp);
        mi=Min(mi,Min(b,-b)+tmp);
        ans=Min(ans,mi);
        cout.flags(ios::fixed);
        cout.precision(12);
        cout<<ans<<endl;
        //printf("%.12Lf\n",ans);
    }
    return 0;
}
