#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct point{
	int x, y;
	bool operator<(const point& rhs) const{
		if(x != rhs.x) return x < rhs.x;
		return y > rhs.y;
	}
};
int N, size;
vector<int> vx, vy;
point ps[300003];
pair<int,int> t[1200003];
pair<int,int> dist[300003];
pair<int,int> merge(pair<int,int>& p1, pair<int,int>& p2){
	if(p1.first < p2.first) return p2;
	if(p1.first > p2.first) return p1;
	return {p1.first, (p1.second + p2.second) % mod};
}
void update(int pos, pair<int,int> p){
	pos += size;
	t[pos] = merge(t[pos], p);
	for(; pos > 1; pos /= 2){
		auto& par = t[pos / 2];
		auto c1 = t[pos], c2 = t[pos ^ 1];
		par = merge(c1, c2);
	}
}
pair<int,int> query(int l, int r){
	pair<int,int> ret = {-inf, 0};
	for(l += size, r += size; l <= r; l /= 2, r /= 2){
		if(l & 1) ret = merge(ret, t[l++]);
		if(~r & 1) ret = merge(ret, t[r--]);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	for(int i = 0 ; i < 1200000; i++) t[i] = {-inf, 0};
	cin >> N;
	for(size = 1; size <= N; size *= 2);
	vx.resize(N), vy.resize(N);
	for(int i = 0 ; i < N; i++){
		int x, y;
		cin >> x >> y;
		ps[i] = {x, y};
		vx[i] = x, vy[i] = y;
	}
	sort(all(vx)), sort(all(vy));
	for(int i = 0 ; i < N; i++){
		int& x = ps[i].x, &y = ps[i].y;
		x = lower_bound(all(vx), x) - vx.begin() + 1;
		y = lower_bound(all(vy), y) - vy.begin() + 1;
	}

	sort(ps, ps + N);
	update(0, {0, 1});
	for(int i = 0 ; i < N; i++){
		auto p = ps[i];
		dist[i] = query(0, p.y - 1);
		dist[i].first = (dist[i].first + 1) % mod;
		update(p.y, dist[i]);
	}
	auto ans = query(0, vy.size() + 1);

	cout << ans.first << '\n' << ans.second;
	return 0;
}