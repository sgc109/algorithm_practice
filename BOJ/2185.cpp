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
	int x1, y1, x2, y2;
};
int N;
rect rects[5003];
vector<pair<int,int> > v;
multiset<pair<int,int> > st;
int main() {
	fastio();
	cin >> N;
	for(int i = 1 ; i <= N; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rects[i] = rect{min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2)};
	}
	ll ans = 0;
	for(int k = 0 ; k < 2; k++){
		v.clear();
		st.clear();
		for(int i = 1 ; i <= N; i++){
			v.emplace_back(rects[i].x1, -i);
			v.emplace_back(rects[i].x2, i);
		}
		sort(all(v));
		int prv = -inf;
		for(auto p : v){
			int cur = p.first;
			int id = p.second;
			int isEnd = id > 0;
			id = abs(id);
			if(prv != -inf){
				int cnt = 0;
				int last = -inf;
				for(auto rng : st){
					if(last < rng.first) cnt++;
					last = max(last, rng.second);
				}
				ans += 2 * cnt * (cur - prv);
			}
			auto r = rects[id];
			if(isEnd) st.erase(st.find({r.y1, r.y2}));
			else st.insert({r.y1, r.y2});
			prv = cur;
		}
		for(int i = 1; i <= N; i++) {
			swap(rects[i].x1, rects[i].y1);
			swap(rects[i].x2, rects[i].y2);
		}
	}
	cout << ans;
	return 0;
}