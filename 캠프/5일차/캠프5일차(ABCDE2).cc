#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
// #define mp make_pair
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
typedef vector<pair<int,int> > vii;
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
int N,M;
vi adj[2003];
int arr[2003][2003];
vii edges;
void YES(){
	printf("1");
	exit(0);
}
int main() {
	inp2(N,M);
	FOR(i,M) {
		int a,b;
		inp2(a,b);
		arr[a][b]=arr[b][a]=1;
		adj[a].pb(b);
		adj[b].pb(a);
		edges.pb({a,b});
		edges.pb({b,a});
	}
	FOR(i,edges.size()){
		FOR(j,edges.size()){
			int A=edges[i].first, B=edges[i].second;
			int C=edges[j].first, D=edges[j].second;
			if(A==B||A==C||A==D||B==C||B==D||C==D) continue;
			if(!arr[B][C]) continue;
			for(auto E : adj[D]){
				if(A!=E&&B!=E&&C!=E) YES();
			}
		}
	}
	printf("0");
	return 0;
}
