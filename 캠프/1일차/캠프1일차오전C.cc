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
const int MAX_N = 502;

int n,m;
int map[MAX_N][MAX_N];
void YES(){
	printf("YES");
	exit(0);
}
void NO(){
	printf("NO");
	exit(0);
}
bool inRange(int i, int j){
	return 0<=i&&i<n&&0<=j&&j<m;
}
int dy[6][2] = {{1,1},{0,1},{0,1},{1,1},{0,0},{1,2}};
int dx[6][2] = {{0,1},{1,0},{1,1},{-1,0},{1,2},{0,0}};

void solve(int pos, int cnt){
	if(pos==n*m) {
		if(cnt==n*m/3) YES();
		else return;
	}
	int hereI=pos/m;
	int hereJ=pos%m;
	// printf("(%d, %d)\n",hereI,hereJ);
	if(map[hereI][hereJ]) solve(pos+1,cnt);
	else {
		FOR(i,6){
			bool wrong=false;
			FOR(j,2){
				int thereI=hereI+dy[i][j];
				int thereJ=hereJ+dx[i][j];
				if(!inRange(thereI,thereJ)||map[thereI][thereJ]) wrong=true;
			}
			if(wrong) continue;
			FOR(j,2){
				int thereI=hereI+dy[i][j];
				int thereJ=hereJ+dx[i][j];
				map[thereI][thereJ]=1;
			}
			map[hereI][hereJ]=1;
			solve(pos+1,cnt+1);
			FOR(j,2){
				int thereI=hereI+dy[i][j];
				int thereJ=hereJ+dx[i][j];
				map[thereI][thereJ]=0;
			}
			map[hereI][hereJ]=0;
		}
	}
}
int main() {
	inp2(n,m);
	if((n*m)%3) NO();
	solve(0,0);
	NO();
	return 0;
}