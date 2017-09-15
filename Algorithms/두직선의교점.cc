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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
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

bool lineIntersect(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x){
	double den = (b-a).cross(d-c);
	if(fabs(den)<EPSILON) return false;
	x = a+(b-a)*((c-a).cross(d-c)/den);
	return true;
}
vector2 points[4];
vector2 inter;
int main() {
	FOR(i,4){
		double x,y;
		scanf("%lf%lf",&x,&y);
		points[i]=vector2(x,y);
	}
	if(lineIntersect(points[0],points[1],points[2],points[3],inter)) printf("(%.5lf, %.5lf)",inter.x,inter.y);
	else printf("No intersection!");
	return 0;
}
