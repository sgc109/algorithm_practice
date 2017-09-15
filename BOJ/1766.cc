#include <bits/stdc++.h>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
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
typedef vector<pair<int,int> > vii;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M;
int i,j,k;
vi adj[32003];
priority_queue<int> pq;
int degree[32003];
int main() {
	inp2(N,M);
	FOR(i,M){
		int a,b;
		inp2(a,b);
		adj[a].pb(b);
		degree[b]++;
	}
	REP(i,1,N) if(!degree[i]) pq.push(-i);
	while(!pq.empty()){
		int here = -pq.top();
		pq.pop();
		printf("%d ",here);
		for(int there : adj[here]){
			degree[there]--;
			if(!degree[there]) pq.push(-there);
		}
	}

}
