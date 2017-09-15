	#include <bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	const int mod = 1e9+7;
	const int inf = 0x3c3c3c3c;
	const long long infl = 0x3c3c3c3c3c3c3c3c;

	int ans[100003];
	vector<int> G[100003];
	int N;
	vector<int> oper[100003];
	set<int> stt;
	void dfs(int here, set<int>& st){
		vector<int> rm, add;
		for(int op : oper[here]){
			if(op < 0) {
				auto it = st.find(-op);
				if(it != st.end()) rm.push_back(*it), st.erase(it);
			}
			else {
				auto it = st.find(op);
				if(it == st.end()) add.push_back(op), st.insert(op);
			}
		}
		ans[here] = st.size();
		for(int there : G[here]){
			dfs(there, st);
		}
		for(int it : rm) st.insert(it);
		for(int it : add) st.erase(it);
	}
	int main() {
		cin >> N;
		for(int i = 2; i <= N; i++){
			int p;
			cin >> p;
			G[p].push_back(i);	
		}
		for(int i = 1; i <= N; i++){
			int K;
			cin >> K;
			for(int j = 0 ; j < K; j++){
				int a;
				cin >> a;
				oper[i].push_back(a);
			}
		}
		dfs(1, stt);
		for(int i = 1 ; i <= N; i++) cout << ans[i] << endl;
		return 0;
	}