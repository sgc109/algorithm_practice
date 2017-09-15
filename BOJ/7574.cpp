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
	int x, y;
};
int N, R, D, x, y, root;
int par[100003];
vector<pair<int,int> > v;
rect rects[100003];
set<pair<int,int> > stUp, stDwn;

int find(int a){
	return par[a] == a ? a : par[a] = find(par[a]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	par[a] = b;
}
int same(int a, int b){
	return find(a) == find(b);
}

int main() {
	fastio();
	for(int i = 0 ; i < 100003; i++) par[i] = i;
	cin >> N >> R;
	for(int i = 1 ; i <= N; i++) {
		cin >> x >> y;
		if(!x && !y) root = i;
		rects[i] = rect{x, y};
	}
	cin >> D;
	for(int k = 0 ; k < 2; k++){
		for(int i = 1 ; i <= N; i++) {
			v.pb({rects[i].x, -i});
			v.pb({rects[i].x + R, i});
		}
		sort(all(v));
		for(auto p : v){
			int pos = p.first;
			int isEnd = p.second > 0;
			int id = abs(p.second);
			auto r = rects[id];
			if(isEnd){
				stDwn.erase({r.y, id});
				stUp.erase({r.y + R, id});
				auto itDwn = stDwn.lower_bound({r.y + R, 0});	
				if(itDwn != stDwn.end()){
					if(r.y + R < (*itDwn).first && (*itDwn).first <= r.y + R + D) {
						merge(id, (*itDwn).second);
					}
				}
				auto itUp = stUp.lower_bound({r.y, 0});
				if(itUp != stUp.begin()){
					--itUp;
					if(r.y - D <= (*itUp).first && (*itUp).first < r.y){
						merge(id, (*itUp).second);
					}
				}
			}
			else {
				stDwn.insert({rects[id].y, id});
				stUp.insert({rects[id].y + R, id});
			}
		}

		for(int i = 1 ; i <= N; i++) swap(rects[i].x, rects[i].y);
		stUp.clear(), stDwn.clear(), v.clear();
	}

	int ans = 0;
	for(int i = 1 ; i <= N; i++){
		if(same(root, i)) ans = max(ans, rects[i].x + rects[i].y + 2 * R);
	}
	cout << ans;
	return 0;
}