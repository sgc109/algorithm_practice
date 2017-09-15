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
int T,N,M;
char pane[503][503];
enum{VER=0,HOR=1};
int dy[] = {0,1,0,-1};
int dx[] = {-1,0,1,0};
int inRange(int i, int j){
	return 0<=i&&i<N&&0<=j&&j<M;
}
int cantW(int i, int j){
	return !inRange(i,j)||pane[i][j]!='W';
}
int NOT(int x){
	return x^1;
}
int TRANS(int i, int j, int dir){
	int x = i*M+j;
	return 2*(2*x+dir);
}
vector<int> G[1000003];
vector<pair<int,int> > sorted;
stack<int> s;
int order[1000003], sccId[1000003];
int cnt, sccCnt;
int tarjan(int here){
	s.push(here);
	order[here] = cnt++;
	int ret = order[here];
	for(int there : G[here]){
		if(sccId[there]!=-1) continue;
		if(order[there]!=-1) ret = min(ret, order[there]);
		else ret = min(ret, tarjan(there));
	}
	if(ret == order[here]){
		while(1){
			int p = s.top();
			s.pop();
			sccId[p] = sccCnt;
			if(p==here) break;
		}
		sccCnt++;
	}
	return ret;
}
int main() {
	inp1(T);
	while(T--){
		sorted.clear();
		memset(order,-1,sizeof(order));
		memset(sccId,-1,sizeof(sccId));
		cnt = 0, sccCnt = 0;
		while(!s.empty()) s.pop();
		FOR(i,1000003) G[i].clear();
		int cntB=0, cntW=0;		
		inp2(N,M);
		FOR(i,N) scanf("%s",pane[i]);
		bool imposs=false;
		FOR(i,N){
			FOR(j,M){
				if(pane[i][j]=='B') {
					cntB++;
					if(cantW(i-1,j)&&cantW(i+1,j)) {imposs=true; goto hell;}
					if(cantW(i,j-1)&&cantW(i,j+1)) {imposs=true; goto hell;}
					if(cantW(i-1,j)) G[TRANS(i,j,VER)].pb(NOT(TRANS(i,j,VER)));
					else if(cantW(i+1,j)) G[NOT(TRANS(i,j,VER))].pb(TRANS(i,j,VER));
					if(cantW(i,j+1)) G[TRANS(i,j,HOR)].pb(NOT(TRANS(i,j,HOR)));
					else if(cantW(i,j-1)) G[NOT(TRANS(i,j,HOR))].pb(TRANS(i,j,HOR));
				}
				else if(pane[i][j]=='W'){
					cntW++;
					FOR(k,4){
						if(pane[i+dy[k]][j+dx[k]]!='B') continue;
						FOR(l,4){
							if(k==l) continue;
							if(pane[i+dy[l]][j+dx[l]]!='B') continue;
							int dir1 = k%2?VER:HOR;
							int dir2 = l%2?VER:HOR;
							int tf1 = k<2?1:0;
							int tf2 = l<2?1:0;
							int a = TRANS(i+dy[k],j+dx[k],dir1);
							int b = TRANS(i+dy[l],j+dx[l],dir2);
							if(!tf1) a = NOT(a);
							if(!tf2) b = NOT(b);
							G[a].pb(NOT(b));
						}
					}
				}
			}
		}
		hell:
		if(imposs || (cntW!=2*cntB)){
			printf("NO\n");
			continue;
		}
		int V = 4*N*M;
		FOR(i,V) if(order[i]==-1) tarjan(i);
		FOR(i,V) sorted.pb({-sccId[i],i});
		sort(all(sorted));
		imposs = false;
		FOR(i,sz(sorted)-1) {
			if(sorted[i].first == sorted[i+1].first && (sorted[i].second^1) == sorted[i+1].second) {
				imposs=true;
			}
		}
		if(imposs) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
