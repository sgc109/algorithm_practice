#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
vector<int> dishes[53];
set<pair<int,int> > st;
int exist[10003];
int psum[10003];
int main() {
	cin >> T;
	for(int t = 1;  t <= T; t++){
		memset(exist,0,sizeof(exist));
		st.clear();
		for(int i = 0 ; i < 53; i++) dishes[i].clear();

		cin >> N;
		int cnt1 = 0;
		for(int i = 0 ; i < N; i++){
			int h;
			cin >> h;
			for(int j = 0 ; j < h; j++){
				int l;
				cin >> l;
				exist[l] = 1;
				dishes[i].push_back(l);
			}
		}

		for(int i = 1 ; i <= 10000; i++) psum[i] = psum[i-1] + exist[i];

		for(int i = 0 ; i < N; i++){
			for(int j = 0 ; j < dishes[i].size()-1; j++){
				int u = dishes[i][j];
				int v = dishes[i][j+1];
				if(u == v) continue;
				int c = psum[v-1] - psum[u];
				if(u + 1 == v) c = 0;
				if(c > 0 || st.count({u,v})) cnt1++;
				st.insert({u,v});
			}
		}

		int ans = 2*cnt1 + N - 1;

		cout << "#testcase" << t << endl;
		cout << ans << endl;
	}	
	return 0;
}
	