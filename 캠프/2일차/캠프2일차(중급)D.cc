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
#include <deque>
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
	vector2(double _x, double _y) : x(_x),y(_y){}
	vector2(){}
	vector2 operator - (const vector2& rhs) const{return vector2(x-rhs.x,y-rhs.y);}
	double dot(vector2& rhs){return x*rhs.x+y*rhs.y;}
	double cross(vector2& rhs){return x*rhs.y-y*rhs.x;}
};

int n;
int x[52],y[52];
vector2 points[52];

int main() {
	inp1(n);
	if(n<=3) {
		printf("%d",n);
		return 0;
	}
	FOR(i,n) {
		inp2(x[i],y[i]);
		points[i]=vector2(x[i],y[i]);
	}
	
	int ans=3;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			FOR(k,n){
				if(i==k||j==k) continue;
				int cnt=0;
				FOR(l,n){
					if(i==l||j==l||k==l) continue;
					auto line1 = points[i]-points[j];
					auto line2 = points[i]-points[l];
					auto line3 = points[k]-points[l];
					if(line1.cross(line2)==0||line1.dot(line3)==0) cnt++;
				}
				ans=max(ans,cnt+3);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
