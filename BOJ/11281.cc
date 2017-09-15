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

int sccid[200003];
int order[200003];
int cnt, sccCnt;
stack<int> s;
int N,M,a,b;
vector<int> G[200003];
int trueFalse[100003];
int NOT(int x){
	return x^1;
}
int TRANS(int x){
	if(x<0) return 2*(-x-1)+1;
	return 2*(x-1);
}
int tarjan(int here){
	order[here] = cnt++;
	s.push(here);
	int ret = order[here];
	for(int there : G[here]){
		if(sccid[there]!=-1) continue;
		if(order[there]==-1) ret = min(ret, tarjan(there));
		else ret = min(ret, order[there]);
	}
	if(ret>=order[here]){
		while(!s.empty()){
			int p = s.top();
			sccid[p] = sccCnt;
			s.pop();
			if(p==here) break;
		}
		sccCnt++;
	}
	return ret;
}
int main() {
	memset(order,-1,sizeof(order));
	memset(sccid,-1,sizeof(sccid));
	memset(trueFalse,-1,sizeof(trueFalse));
	inp2(N,M);
	FOR(i,M){
		inp2(a,b);
		G[NOT(TRANS(a))].push_back(TRANS(b));
		G[NOT(TRANS(b))].push_back(TRANS(a));
	}
	FOR(i,2*N) if(order[i]==-1) tarjan(i);

	vii sorted;
	FOR(i,2*N) sorted.push_back({-sccid[i],i});
	sort(all(sorted));
	bool imposs=false;
	FOR(i,2*N-1) {
		if(sorted[i].first == sorted[i+1].first && (sorted[i].second^1) == sorted[i+1].second) {
			imposs=true;
			break;
		}
	}
	if(imposs){
		printf("0\n");
		return 0;
	}
	FOR(i,2*N){
		int here = sorted[i].second;
		int hereId = here/2;
		if(trueFalse[hereId] !=-1) continue;
		if(here&1) trueFalse[hereId] = 1;
		else trueFalse[hereId] = 0;
	}
	printf("1\n");
	FOR(i,N){
		printf("%d ",trueFalse[i]);
	}
	return 0;
}
