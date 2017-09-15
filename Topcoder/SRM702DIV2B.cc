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
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

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


class GridSort{
public:
	vvi v;
	string sort(int n, int m, vector <int> grid){
		v = vvi(n,vi(m));
		FOR(i,n){
			FOR(j,m){
				v[i][j]=grid[i*m+j];
			}
		}
		vi a;
		FOR(i,n){
			a.pb(v[0][0]-v[i][0]);
			if(abs(a.back())%m!=0) return "Impossible";
		}
		
		REP(j,1,m){
			FOR(i,n){
				if(v[0][j]-a[i]!=v[i][j]) return "Impossible";
			}
		}
		return "Possible";
	}

};

int main(){
	GridSort obj;
	cout << obj.sort(3,2,{1,4,2,5,3,6});
	return 0;
}