#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 30;

struct Rect{
	double x1,y1,x2,y2;
} rects[MAX_N];
double Xs[2*MAX_N];
double Ys[2*MAX_N];


bool inRange(double x1, double y1, double x2, double y2, Rect& rect){
	if(rect.x1 <= x1 && x2 <= rect.x2 && rect.y1 <= y1 && y2 <= rect.y2) return true;
	return false;
}
double ans;
int main() {
	int n;
	inp1(n);
	FOR(i,n){
		double x1,y1,x2,y2,h,w;
		scanf("%lf%lf%lf%lf",&x1,&y1,&w,&h);
		x2 = x1+w;
		y2 = y1+h;
		rects[i].x1 = x1;
		rects[i].y1 = y1;
		rects[i].x2 = x2;
		rects[i].y2 = y2;
		Xs[2*i] = x1;
		Xs[2*i+1] = x2;
		Ys[2*i] = y1;
		Ys[2*i+1] = y2;
	}

	sort(Xs,Xs+2*n);
	sort(Ys,Ys+2*n);
	for(int i = 0; i < 2*n-1; ++i){
		for(int j = 0; j < 2*n-1; ++j){
			for(int k = 0; k < n; ++k){
				if(inRange(Xs[i],Ys[j],Xs[i+1],Ys[j+1],rects[k])) {
					ans+=((Xs[i+1]-Xs[i])*(Ys[j+1]-Ys[j]));
					break;
				}
			}
		}
	}

	if((double)(int)ans == ans) printf("%d",(int)ans);
	else printf("%.2lf",ans);
	return 0;
}