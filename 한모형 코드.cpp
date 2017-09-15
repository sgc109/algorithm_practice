#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define eps 1e-9
#define pii pair<int,int>
#define pdd pair<double, double>
using namespace std;

const double pi = 3.1415926535897932;
double dist(double x1,double y1, double x2, double y2){return sqrt(pow(x2-x1,2)+pow(y2-y1,2));}
double max(double a, double b){return a<b? b:a;}

int main(){
    double x0,y0,v,T,r0; scanf("%lf %lf %lf %lf",&x0,&y0,&v,&T);
    r0 = v*T;
    int N; scanf("%d",&N);
    vector<pdd> line;
    while(N--){
        double x,y,r; scanf("%lf %lf %lf",&x,&y,&r);
        x-=x0;
        y-=y0;
        double d = dist(0,0,x,y);
        if( (r+r0) *(r+r0) < x*x + y*y ) {
            continue;
        }
        else if( x*x+y*y< r*r + eps) {
            printf("1.00000000000\n");
            return 0;
        }
        double gac=0;
        //printf("%lf %lf\n",r0, d);
        if(r0 >= d || abs(r0-d)<=eps) gac = asin(r/d);
        else gac = acos((r0*r0 + d*d - r*r)/(2*r0*d));
        if(gac <0) gac+=2*pi;
        double midgac= atan2(y,x);
        
        double start = midgac-gac;
        double end = midgac+gac;
        if(start > 2*pi) start-=2*pi;
        if(start < 0 ) start +=2*pi;
        if(end > 2*pi) end-=2*pi;
        if(end < 0 ) end +=2*pi;
        if(start - end > eps){
            line.push_back(make_pair(0,end));
            line.push_back(make_pair(start,2*pi));
        }else{
            line.push_back(make_pair(start,end));
        }
    
    //        printf("%lf, %lf,  %lf, %lf\n",midgac, gac, start, end);
    }   
    sort(line.begin(),line.end());
    double Ans=0, last=0;
    for(auto cur : line){
        if(last <cur.first) last = cur.first;
        
        //    printf("line : %lf, %lf, %lf\n", last, cur.first, cur.second);
        Ans += max((cur.second - last),0);
        if(last < cur.second) last = cur.second;
    }
    printf("%.11lf\n",Ans/2/pi);
    return 0;
}