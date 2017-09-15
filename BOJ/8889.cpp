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

struct rect{
	int l,r,u,d;
};
int T, N, K;
rect rects[20003];
vector<pair<int,int> > v;
set<pair<int,int> > st;
vector<int> G[20003];
int in[20003];
int dist[20003];
int main() {
	fastio();
	cin >> T;
	while(T--){
		memset(in,0,sizeof(in));
		for(int i = 0 ; i < 20003; i++) G[i].clear();
		v.clear();
		st.clear();
		cin >> N;
		for(int i = 1 ; i <= N; i++){
			rects[i].l = rects[i].d = inf;
			rects[i].r = rects[i].u = -1;
			cin >> K;
			for(int j = 0 ; j < K; j++){
				int y, x;
				cin >> x >> y;
				rects[i].l = min(rects[i].l, x);
				rects[i].r = max(rects[i].r, x);
				rects[i].u = max(rects[i].u, y);
				rects[i].d = min(rects[i].d, y);
			}
			v.emplace_back(rects[i].l, -i);
			v.emplace_back(rects[i].r, i);
		}
		sort(all(v));
		for(auto p : v){
			int id = p.second;
			int posY = p.first;
			int isEnd = id > 0;
			id = abs(id);
			auto r = rects[id];
			if(isEnd) st.erase({r.u, id});
			else {
				auto it = st.lower_bound({r.u, 0});
				if(it != st.end()) {
					int parId = (*it).second;
					if(r.d >= rects[parId].d) G[parId].pb(id), in[id]++;
				} 
				st.insert({r.u, id});
			}
		}
		queue<int> q;
		for(int i = 1; i <= N; i++) if(!in[i]) q.push(i), dist[i] = 1;
		int ans = 1;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int nxt : G[cur]){
				dist[nxt] = dist[cur] + 1;
				ans = max(ans, dist[nxt]);
				in[nxt]--;
				if(!in[nxt]) q.push(nxt);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}