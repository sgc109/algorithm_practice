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
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M;
char maap[53][53];
int d[253][253];
int dist[53][53];
vii spot;
int dy[]={-1,0,0,1};
int dx[]={0,-1,1,0};
bool inRange(int i, int j){
	return 0<=i&&i<N&&0<=j&&j<N;
}
void bfs(int startId){
	memset(dist,0x3c,sizeof(dist));
	queue<pii> q;
	dist[spot[startId].first][spot[startId].second]=0;
	q.push({spot[startId].first,spot[startId].second});
	while(!q.empty()){
		int hereI = q.front().first;
		int hereJ = q.front().second;
		q.pop();
		FOR(k,4){
			int thereI = hereI+dy[k];
			int thereJ = hereJ+dx[k];
			if(!inRange(thereI,thereJ)||maap[thereI][thereJ]=='1'||dist[thereI][thereJ]!=INF) continue;
			q.push({thereI,thereJ});
			dist[thereI][thereJ]=dist[hereI][hereJ]+1;
		}
	}
	FOR(i,M){
		if(i==startId) continue;
		d[startId][i]=dist[spot[i].first][spot[i].second];
	}
}
viii edges;
int p[253],h[253];
int find(int here){
	if(p[here]==here) return here;
	return p[here]=find(p[here]);
}
void merge(int a, int b){
	a=find(a),b=find(b);
	if(h[a]<h[b]) swap(a,b);
	p[b]=a;
	if(h[a]==h[b]) h[a]++;
}
int main() {
	memset(d,0x3c,sizeof(d));
	inp2(N,M);
	M++;
	FOR(i,N) scanf("%s",maap[i]);
	FOR(i,N){
		FOR(j,N){
			if(maap[i][j]=='S'||maap[i][j]=='K') spot.pb({i,j});
		}
	}
	FOR(i,M) bfs(i);
	FOR(i,M) p[i]=i,h[i]=1;
	FOR(i,M){
		REP(j,i+1,M-1){
			edges.pb({d[i][j],{i,j}});
		}
	}
	sort(all(edges));
	ll ans=0;
	for(auto e : edges){
		int u = e.second.first, v = e.second.second;
		int cost = e.first;
		// printf("u:%d, v:%d, cost:%d\n",u,v,cost);
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=cost;
	}
	if(ans>=INF) ans=-1;
	printf("%d",ans);
	return 0;
}
