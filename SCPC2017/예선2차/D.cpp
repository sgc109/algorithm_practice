#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAXN = 1000;

int N, T, P;
vector<pair<int,int> > G[MAXN+3];
int root;
ll dp1[MAXN+3][MAXN+3], dp2[MAXN+3][MAXN+3];
int dist2root[MAXN+3];
int almostPar[MAXN+3];
ll farest[MAXN+3];
ll excFarest[MAXN+3];
ll getFarest(int cur, int dad){
	ll ret = 0;
	for(auto p : G[cur]){
		if(p.first == dad) continue;
		ret = max(ret, getFarest(p.first, cur) + p.second);
	}
	return farest[cur] = ret;
}
void getAlmostPar(int cur, int dad, int alDad){
	almostPar[cur] = alDad;
	for(auto p : G[cur]){
		if(p.first == dad) continue;
		getAlmostPar(p.first, cur, (cur == root ? p.first : alDad));
	}
}
void dfs1(int cur, int sel){
	for(auto p : G[cur]){
		int c = p.first;
		int cost = p.second;
		for(int i = 0 ; i <= sel; i++){
			for(int j = 0 ; i + j <= sel; j++){

			}
		}
	}	
}
void dfs2(int cur, int sel){

}
int main() {
	setbuf(stdout, NULL);
	root = 0;
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		for(int i = 0 ; i < MAXN+3; i++) G[i].clear();
		scanf("%d",&N);
		for(int i = 0 ; i < N - 1; i++){
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			a--,b--;
			G[a].push_back({b,w});
			G[b].push_back({a,w});
		}
		scanf("%d",&P);
		getFarest(root, -1);
		getAlmostPar(root, -1, root);
		multiset<ll> st;
		for(auto p : G[root]) st.insert(farest[p.first] + p.second);
		for(auto p : G[root]){
			st.erase(st.find(farest[p.first] + p.second));
			if(st.size() == 0) excFarest[p.first] = 0;
			else excFarest[p.first] = *(--st.end());
			st.insert(farest[p.first] + p.second);
		}
	}
	return 0;
}