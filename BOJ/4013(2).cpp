#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAXN = 100;

class SCC{
	vector<vector<int> > G;
	vector<int> sccId, order;
	int visitCnt, sccCnt, size;
	stack<int> stck;
public:
	SCC(){}
	SCC(vector<int>* graph, int size){
		this->size = size;
		G = vector<vector<int> >(size);
		for(int i = 0 ; i < size; i++) G[i] = graph[i];
		sccId = vector<int>(size, -1);
		order = vector<int>(size, -1);
		visitCnt = sccCnt = 0;
		for(int i = 0 ; i < size; i++) {
			if(order[i] == -1) dfs(i);
		}
		for(int i = 0 ; i < size; i++) sccId[i] = sccCnt - sccId[i] - 1;
	}
	int dfs(int cur){
		stck.push(cur);
		int ret = order[cur] = visitCnt++;
		for(int next : G[cur]){
			if(order[next] == -1) ret = min(ret, dfs(next));
			else if(sccId[next] == -1) ret = min(ret, order[next]);
		}
		if(order[cur] == ret){
			while(1){
				int top = stck.top();
				stck.pop();
				sccId[top] = sccCnt;
				if(top == cur) break;
			}
			sccCnt++;
		}
		return ret;
	}
	vector<vector<int> > getCompGraph(){
		vector<vector<int> > compG = vector<vector<int> >(sccCnt);
		for(int cur = 0 ; cur < size; cur++){
			for(int next : G[cur]){
				if(sccId[cur] == sccId[next]) continue;
				compG[sccId[cur]].push_back(sccId[next]);
			}
		}
		for(int i = 0; i < sccCnt; i++) {
			sort(compG[i].begin(), compG[i].end());
			compG[i].erase(unique(compG[i].begin(), compG[i].end()), compG[i].end());
		}
		return compG;
	}
	vector<int> getSccId(){
		return sccId;
	}
	int getSccCnt(){
		return sccCnt;
	}
};

int N,M,P,S;
vector<int> G[500003];
int A[500003];
int B[500003];
ll cash[500003];
int isRest[500003];
ll dp[500003];
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0 ; i < M; i++){
		int a,b;
		cin >> a >> b;
		a--,b--;
		G[a].push_back(b);
	}
	for(int i = 0 ; i < N; i++) cin >> A[i];
	cin >> S >> P;
	for(int i = 0 ; i < P; i++){
		int a;
		cin >> a;
		a--;
		B[a] = 1;
	}

	SCC scc(G, N);
	vector<int> sccId = scc.getSccId();
	int sccCnt = scc.getSccCnt();
	for(int i = 0 ; i < N; i++) cash[sccId[i]] += A[i];
	for(int i = 0 ; i < N; i++) isRest[sccId[i]] |= B[i];

	memset(dp,0xc3,sizeof(dp));
	vector<vector<int> > compG = scc.getCompGraph();

	dp[sccId[S-1]] = 0;
	ll ans = 0;
	for(int cur = 0 ; cur < sccCnt; cur++){
		dp[cur] += cash[cur];
		if(isRest[cur]) ans = max(ans, dp[cur]);
		for(int next : compG[cur]){
			dp[next] = max(dp[next], dp[cur]);
		}
	}

	cout << ans;
	return 0;
}