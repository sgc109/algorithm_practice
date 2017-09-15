#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct SCC{
	vector<vector<int> > G;
	vector<int> sccId, order;
	int visitCnt, sccCnt, size;
	stack<int> stck;
	SCC(){}
	SCC(int size){
		this->size = size;
		G = vector<vector<int> >(size);
	}
	void buildSCC(){
		sccId = vector<int>(size, -1);
		order = vector<int>(size, -1);
		visitCnt = sccCnt = 0;
		for(int i = 0 ; i < size; i++) {
			if(order[i] == -1) dfs(i);
		}
		for(int i = 0 ; i < size; i++) sccId[i] = sccCnt - sccId[i] - 1;
	}
	void addEdge(int from, int to){
		G[from].push_back(to);
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
};
struct TwoSAT{
	int size;
	SCC scc;
	vector<int> ans;
	bool isPossible;
	TwoSAT(int size){
		this->size = size;
		scc = SCC(size);
	}
	void buildTwoSAT(){
		scc.buildSCC();
		vector<int> sccId = scc.sccId;
		isPossible = true;
		for(int i = 0 ; i < size; i+=2){
			if(sccId[i] == sccId[i+1]) isPossible = false;
		}
		ans = vector<int>(size / 2, -1);
		for(int i = 0; i < size; i += 2){
			ans[i / 2] = sccId[i] > sccId[i + 1];
		}
	}
	void addEdge(int from, int to){
		scc.addEdge(from, to);
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

struct node{
	string S;
	int turn, cnt;
};
int N;
node in[53];
int black[30];
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++){
		string S;
		int turn, cnt;
		cin >> S >> turn >> cnt;
		in[i] = node{S, turn, cnt};
	}
	int ans = 0;
	for(int i = 0 ; i < 26; i++){
		for(int j = i + 1; j < 26; j++){
			for(int k = j + 1; k < 26; k++){
				black[i] = black[j] = black[k] = 1;
				int ok = 1;
				TwoSAT twoSat(52);
				for(int l = 0 ; l < N; l++){
					string s = in[l].S;
					int c1 = s[0] - 'A', c2 = s[1] - 'A';
					int turn = in[l].turn;
					int cnt = in[l].cnt;
					if(black[c1] + black[c2] > 2 - cnt){
						ok = 0;
						break;
					}
					vector<int> cand;
					if(!black[c1]) cand.pb(c1);
					if(!black[c2]) cand.pb(c2);
					if(sz(cand) == 2){
						int c1 = cand[0], c2 = cand[1];
						if(cnt == 2){
							twoSat.addEdge(2 * c1 + turn - 1, 2 * c1 + 2 - turn);
							twoSat.addEdge(2 * c2 + turn - 1, 2 * c2 + 2 - turn);
						}
						else if(cnt == 1){
							twoSat.addEdge(2 * c1 + turn - 1, 2 * c2 + 2 - turn);
							twoSat.addEdge(2 * c1 + 2 - turn, 2 * c2 + turn - 1);
							twoSat.addEdge(2 * c2 + turn - 1, 2 * c1 + 2 - turn);
							twoSat.addEdge(2 * c2 + 2 - turn, 2 * c1 + turn - 1);
						}
						else {
							twoSat.addEdge(2 * c1 + 2 - turn, 2 * c1 + turn - 1);
							twoSat.addEdge(2 * c2 + 2 - turn, 2 * c2 + turn - 1);
						}
					}
					else if(sz(cand) == 1){
						int c1 = cand[0];
						if(cnt == 1) twoSat.addEdge(2 * c1 + turn - 1, 2 * c1 + 2 - turn);
						else twoSat.addEdge(2 * c1 + 2 - turn, 2 * c1 + turn - 1);
					}
				}
				black[i] = black[j] = black[k] = 0;
				if(!ok) continue;
				twoSat.buildTwoSAT();
				auto ret = twoSat.getAns();
				if(sz(ret)) ans++;
			}
		}
	}	
	cout << ans;
	return 0;
}