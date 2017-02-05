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

struct vector2{
	double x,y;
	vector2(double _x, double _y):x(_x),y(_y){}
	vector2(){}
	double size()const{return hypot(x,y);}
	vector2 normalize()const{return vector2(x/size(),y/size());}
	double dot(const vector2& other)const{return x*other.x+y*other.y;}
	double cross(const vector2& other){return x*other.y-y*other.x;}
	vector2 operator + (const vector2& other) const{return vector2(x+other.x,y+other.y);}
	vector2 operator - (const vector2& other) const{return vector2(x-other.x,y-other.y);}
	vector2 operator * (const double k) const{return vector2(x*k,y*k);}
	bool operator == (const vector2& other) const{return x==other.x&&y==other.y;}
	bool operator < (const vector2& other) const{return (x==other.x?y<other.y:x<other.x);}
	vector2 project(const vector2& other) const{
		vector2 r = other.normalize();
		return r*dot(r);	
	}
};

int another(int a, int b){
	int check[3];
	memset(check,0,sizeof(check));
	check[a]=check[b]=1;
	FOR(i,3){
		if(!check[i]) return i;
	}
	return -1;
}
vector2 points[3];
int main() {
	FOR(i,3){
		int x,y;
		inp2(x,y);
		points[i]=vector2(x,y);
	}
	vector2 line1 = points[0]-points[1];
	vector2 line2 = points[0]-points[2];
	if(line1.cross(line2)==0) {
		printf("-1");
		return 0;
	}
	double ansMin=1e20;
	double ansMax=-1;
	FOR(i,3){
		for(int j=i+1;j<3;j++){
			int a1=i,a2=j;
			int b=another(a1,a2);
			vector2 line1=points[a1]-points[b];
			vector2 line2=points[a2]-points[b];
			ansMin=min(ansMin,2*(line1.size()+line2.size()));
			ansMax=max(ansMax,2*(line1.size()+line2.size()));
		}
	}
	printf("%.16lf",ansMax-ansMin);
	return 0;
}
