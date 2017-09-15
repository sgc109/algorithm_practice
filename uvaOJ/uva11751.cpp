#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
vector<int> G[1003];
int sel[1003];
int main() {
	while(cin >> N >> M){
		if(!N && !M) break;
		for(int i = 0 ; i < 1003; i++) G[i].clear();
		memset(sel,0,sizeof(sel));
		for(int i = 0 ; i < M; i++) {
			int a,b;
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int u = 0 ; u < N; u++){
			int ok = 0;
			for(int v : G[u]) if(!sel[v]) ok = 1;
			if(ok) sel[u] = 1;
		}
		for(int u = N-1; u >= 0; u--) {
			int ok = 1;
			for(int v : G[u]) if(!sel[v]) ok = 0;
			if(ok) sel[u] = 0;
		}
		for(int i = 0 ; i < N; i++) cout << sel[i];
		cout << endl;
	}
	return 0;
}