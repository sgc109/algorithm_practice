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
	ll x1, y1, x2, y2;
};
bool overlap(rect a, rect b){
	if(a.x1 == a.x2) {
		if(a.y1 > b.y1) swap(a, b);
		if(a.x1 != b.x1) return false;
		return a.y1 <= b.y1 && b.y1 <= a.y2;
	}
	else {
		if(a.x1 > b.x1) swap(a, b);
		if(a.y1 != b.y1) return false;
		return a.x1 <= b.x1 && b.x1 <= a.x2;
	}
}
rect merge(rect a, rect b){
	if(a.x1 == a.x2) {
		if(a.y1 > b.y1) swap(a, b);
		return rect{a.x1, a.y1, a.x1, max(a.y2, b.y2)};
	}
	else {
		if(a.x1 > b.x1) swap(a, b);
		return rect{a.x1, a.y1, max(a.x2, b.x2), a.y1};
	}	
}
bool cmpHor(rect& a, rect& b){
	if(a.y1 != b.y1) return a.y1 < b.y1;
	return a.x1 < b.x1;
}
bool cmpVer(rect& a, rect& b){
	if(a.x1 != b.x1) return a.x1 < b.x1;
	return a.y1 < b.y1;
}

void update(){
	
}
int N;
vector<rect> tmpHor, tmpVer, hor, ver;

int main() {
	fastio();
	cin >> N;
	for(int i = 1 ; i <= N; i++){
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		auto r = rect{x1, y1, x2, y2};
		if(r.x1 == r.x2) tmpVer.pb(r);
		else tmpHor.pb(r);
	}

	sort(all(tmpHor), cmpHor);
	sort(all(tmpVer), cmpVer);
	for(auto r : tmpHor){
		if(hor.empty()) hor.pb(r);
		else if(overlap(hor.back(), r)) {
			auto tmp = hor.back();
			hor.pop_back();
			hor.pb(merge(tmp, r));
		}
	}
	for(auto r : tmpVer){
		if(ver.empty()) ver.pb(r);
		else if(overlap(ver.back(), r)) {
			auto tmp = ver.back();
			ver.pop_back();
			ver.pb(merge(tmp, r));
		}
	}


	return 0;
}