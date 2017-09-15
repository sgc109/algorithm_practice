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
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

struct point{
	int x,y;
};
point p[4];
int getP(int base, int th){
	if(base==0){
		if(th==1) return 1;
		else return 2;
	}
	else if(base==1){
		if(th==1) return 0;
		else return 2;
	}
	else{
		if(th==1) return 0;
		else return 1;
	}
	return -1;
}
bool about(int base){
	bool con1=false,con2=false;
	if(p[base].x==p[getP(base,1)].x){
		if(p[getP(base,2)].x <= p[base].x) con1=p[base].x>=p[3].x;
		else con1=p[3].x<=p[base].x;
	}
	else{
		if((p[base].y-p[getP(base,1)].y)*(p[getP(base,2)].x-p[base].x)<=(p[getP(base,2)].y-p[base].y)*(p[base].x-p[getP(base,1)].x)) con1=(p[base].y-p[getP(base,1)].y)*(p[3].x-p[base].x)>=(p[3].y-p[base].y)*(p[base].x-p[getP(base,1)].x);
		else con1=(p[base].y-p[getP(base,1)].y)*(p[3].x-p[base].x)<=(p[3].y-p[base].y)*(p[base].x-p[getP(base,1)].x);
	}
	if(p[base].x==p[getP(base,2)].x){
		if(p[getP(base,1)].x <= p[base].x) con2=p[base].x>=p[3].x;
		else con2=p[3].x<=p[base].x;
	}
	else{
		if((p[base].y-p[getP(base,2)].y)*(p[getP(base,1)].x-p[base].x)<=(p[getP(base,1)].y-p[base].y)*(p[base].x-p[getP(base,2)].x)) con2=(p[base].y-p[getP(base,2)].y)*(p[3].x-p[base].x)>=(p[3].y-p[base].y)*(p[base].x-p[getP(base,2)].x);
		else con2=(p[base].y-p[getP(base,2)].y)*(p[3].x-p[base].x)<=(p[3].y-p[base].y)*(p[base].x-p[getP(base,2)].x);
	}
	return con1&&con2;
}
bool on1line(){
	if(p[0].x==p[1].x||p[1].x==p[2].x||p[2].x==p[0].x) {
		if(p[0].x==p[1].x&&p[1].x==p[2].x) return true;
		return false;
	}
	double gi1 = (double)(p[0].y-p[1].y)/(p[0].x-p[1].x);
	double gi2 = (double)(p[1].y-p[2].y)/(p[1].x-p[2].x);
	return gi1==gi2;
}
int main() {
	FOR(i,4){
		int a,b;
		inp2(a,b);
		p[i]={a,b};
	}
	FOR(i,4){
		swap(p[3],p[i]);
		if(on1line()) {
			printf("1");
			return 0;
		}
		swap(p[3],p[i]);
	}
	printf("%d",about(0)||about(1)||about(2));
	
	return 0;
}
