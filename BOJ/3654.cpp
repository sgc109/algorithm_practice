#include <bits/stdc++.h>
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
const int MAX_V = 500003;
int T,N,M;
char pane[503][503];
int dy[] = {-1,0,0,1};
int dx[] = {0,-1,1,0};
vi G[MAX_V];
int NOT(int x){
	return x^1;
}
int TRANS(int i, int j){
	return 2*(i*M+j);
}
int inRange(int i, int j){
	return 0<=i&&i<N&0<=j&&j<M;
}
int isW(int i, int j){
	return inRange(i,j) && pane[i][j] == 'W';
}
int main() {
	inp1(T);
	while(T--){
		FOR(i,MAX_V) G[i].clear();
		inp2(N,M);
		FOR(i,N) scanf("%s",pane[i]);
		int cntB = 0, cntW = 0;
		FOR(i,N){
			FOR(j,M){
				if(pane[i][j] == 'W') cntW++;
				else lf(pane[i][j] == 'B') cntB++;
				if(pane[i][j] == 'W') continue;
				if(isW(i+1,j) && isW(i-1,j)){
					G[NOT(TRANS)]
				}
				else if(isW(i+1,j)){

				}
				else if(isW(i-1,j)) {

				}
			}
		}
	}
	return 0;
}
