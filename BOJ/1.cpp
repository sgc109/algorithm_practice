#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

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
		sort(compG.begin(), compG.end());
		for(int i = 0; i < sccCnt; i++) {
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
class TwoSAT{
	SCC scc;
	vector<int> ans;
	bool isPossible;
public:
	TwoSAT(vector<int>* graph, int size){
		scc = SCC(graph, size);
		vector<int> sccId = scc.getSccId();
		isPossible = true;
		for(int i = 0 ; i < size; i+=2){
			if(sccId[i] == sccId[i+1]) isPossible = false;
		}
		if(isPossible){
			ans = vector<int>(size / 2, -1);
			vector<pair<int,int> > sorted;
			for(int i = 0 ; i < size; i++){
				sorted.push_back({sccId[i], i});
			}
			sort(sorted.begin(), sorted.end());
			for(auto p : sorted){
				int num = p.second;
				int isFalse = num&1;
				if(ans[num / 2] != -1) continue;
				ans[num / 2] = isFalse;
			}
		}
	}
	vector<int> getAns(){
		if(!isPossible) return vector<int>();
		return ans;
	}
};
int NOT(int x){
	return x^1;
}
int TRANS(int x){
	return x*2;
}

int N,K;
vector<int> G[500];
string words[203];
int rev[203][203];
int dp[23][23];
int main() {
	fastio();
	cin >> N >> K;
	for(int i = 0 ; i < N; i++) cin >> words[i];
	for(int i = 0 ; i < N; i++){
		for(int j = i + 1; j < N; j++){
			int maxLen = 0;
			memset(dp,0,sizeof(dp));
			for(int a = 1; a <= (int)words[i].size(); a++){
				for(int b = 1; b <= (int)words[j].size(); b++){
					char c1 = words[i][a - 1];
					char c2 = words[j][b - 1];
					if(c1 == c2) dp[a][b] = dp[a - 1][b - 1] + 1;
					else dp[a][b] = 0;
					maxLen = max(maxLen, dp[a][b]);
				}
			}
			if(maxLen >= K) {
				G[TRANS(i)].push_back(NOT(TRANS(j)));
				G[NOT(TRANS(i))].push_back(TRANS(j));
				G[TRANS(j)].push_back(NOT(TRANS(i)));
				G[NOT(TRANS(j))].push_back(TRANS(i));
				rev[i][j] = rev[j][i] = 1;
			}
		}
	}
	
	TwoSAT sat(G, 2*N);
	vector<int> ans = sat.getAns();
	if((int)ans.size() == 0) return !printf("No\n");
	
	cout << "Yes" << endl;
	int allSame = 1;
	for(int i = 0 ; i < N - 1; i++) if(ans[i] != ans[i+1]) allSame = 0;
	if(!allSame) for(int i = 0 ; i < N; i++) cout << ans[i] + 1 << endl;
	else {
		for(int i = 0 ; i < N; i++){
			int ok = 1;
			ans[i] = !ans[i];
			for(int j = 0 ; j < N; j++){
				if(i == j) continue;
				if(rev[i][j] && ans[i] == ans[j]) ok = 0;
			}
			if(ok){
				for(int i = 0 ; i < N; i++) cout << ans[i] + 1 << endl;
				return 0;		
			}
			ans[i] = !ans[i];
		}
	}

	return 0;
}