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
vector2 points[4];
vi other2(int a, int b){
	vi ret;
	int c[4];
	memset(c,0,sizeof(c));
	c[a]=1,c[b]=1;
	FOR(i,4){
		if(!c[i]) ret.pb(i);
	}
	return ret;
}
int main() {
	int T;
	inp1(T);
	while(T--){
		FOR(i,4){
			int x,y;
			inp2(x,y);
			points[i]=vector2(x,y);
		}
		FOR(i,4){
			for(int j = i+1; j < 4; j++){
				vi other = other2(i,j);
				int a1=i,a2=j,b1=other[0],b2=other[1];
				if(points[a1]<points[a2]) swap(a1,a2);
				if(points[b1]<points[b2]) swap(b1,b2); 

				vector2 line1 = points[a1]-points[a2];
				vector2 line2 = points[b1]-points[b2];
				if(line1.cross(line2)==0){
					swap(a1,b2);
					line1 = points[a1]-points[a2];
					line2 = points[b1]-points[b2];
					if(line1.cross(line2)==0){
						swap(a1,b1);
						line1 = points[a1]-points[a2];
						line2 = points[b1]-points[b2];
						if(line1.dot(line2)==0){
							printf("1\n");
							goto hell;
						}
					}
				}
			}
		}
		printf("0\n");
		hell:
		1;
	}
	return 0;
}
