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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

char adj1[23][23];
char adj2[23][23];
int dist[23];
int N;
int main() {
	memset(dist,0x3c,sizeof(dist));
	inp1(N);
	FOR(i,N) scanf("%s",adj1[i]);
	FOR(i,N) scanf("%s",adj2[i]);
	priority_queue<pair<pii,pii> > pq;
	pq.push({{0,0},{0,0}});
	dist[0]=0;
	while(!pq.empty()){
		int hereD = -pq.top().first.first;
		int here = pq.top().first.second;
		int hereS = pq.top().second.first;
		int hereW = pq.top().second.second;
		pq.pop();
		if(dist[here]<hereD) continue;
		FOR(there,N){
			if(adj1[here][there]=='.') continue;
			int cost1 = adj1[here][there]-'0';
			int cost2 = adj2[here][there]-'0';
			int thereS = hereS+cost1;
			int thereW = hereW+cost2;
			int thereD = thereS*thereW;
			if(dist[there]>thereD) {
				dist[there]=thereD;
				pq.push({{-thereD,there},{thereS,thereW}});
			}
		}
	}
	if(dist[1]>=INF) dist[1]=-1;
	printf("%d",dist[1]);

	return 0;
}
