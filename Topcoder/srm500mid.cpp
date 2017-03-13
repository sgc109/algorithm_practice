#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class FractalPicture{
public:
	struct rect{
		int x1,y1,x2,y2;
		rect(int x1, int y1, int x2, int y2):x1(x1), y1(y1), x2(x2), y2(y2){}
		bool operator==(const rect& rhs){
			return x1==rhs.x1 && y1==rhs.y1 && x2==rhs.x2 && y2==rhs.y2;
		}
		pii rotate(int x, int y, double theta){
			int nx, ny;
			if (theta == PI / 2) nx = -y, ny = x;
			else if (theta == -PI / 2) nx = y, ny = -x;
			else nx = x, ny = y;
			return {nx,ny};
		}
		rect rotateAndResize(double theta){
			pii p1 = rotate(x1,y1,theta);
			pii p2 = rotate(x2,y2,theta);
			pii np1 = {min(p1.first,p2.first), min(p1.second,p2.second)};
			pii np2 = {max(p1.first,p2.first), max(p1.second,p2.second)};
			return rect(np1.first*3, np1.second*3, np2.first*3, np2.second*3);
		}
		rect moveTo(int dx, int dy){
			return rect(x1+dx, y1+dy, x2+dx, y2+dy);
		}
		rect crossWith(const rect &rhs){
			return rect(max(x1, rhs.x1), max(y1, rhs.y1), min(x2, rhs.x2), min(y2, rhs.y2));
		}
		bool isCross(const rect& rhs){
			return !((x2 < rhs.x1) || (rhs.x2 < x1) || (y2 < rhs.y1) || (rhs.y2 < y1));
		}
		bool isEmpty(){
			return !x1&&!x2&&!y1&&!y2;
		}
	};
	double go(int gen, rect R){
		if(gen>500) return 0;
		if(R.isEmpty()) return 0;
		rect fullR = rect(-27,0,27,81);
		if(fullR.crossWith(R) == fullR) return 54*(500-gen) + 81;
		rect R1 = (!R.isCross(rect(-27,45,0,63)) ? rect(0,0,0,0) : R.crossWith(rect(-27,45,0,63)).moveTo(0,-54).rotateAndResize(-PI/2));
		rect R2 = (!R.isCross(rect(-9,54,9,81)) ? rect(0,0,0,0) : R.crossWith(rect(-9,54,9,81)).moveTo(0,-54).rotateAndResize(0));
		rect R3 = (!R.isCross(rect(0,45,27,63)) ? rect(0,0,0,0) : R.crossWith(rect(0,45,27,63)).moveTo(0,-54).rotateAndResize(PI/2));
		double ret=0;
		rect add = R.crossWith(rect(0,0,0,54));
		if(R.isCross(rect(0,0,0,54))) ret+=add.y2-add.y1;
		double ans1 = go(gen+1,R1)/3;
		double ans2 = go(gen+1,R2)/3;
		double ans3 = go(gen+1,R3)/3;
		ret += ans1+ans2+ans3;
		return ret;
	}
	double getLength(int x1, int y1, int x2, int y2){
		return go(1,rect(x1,y1,x2,y2));
	}
};