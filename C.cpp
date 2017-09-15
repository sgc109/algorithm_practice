#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Point{
	int x, y;
	bool operator<(const Point& rhs) const{
		return x < rhs.x;
	}
};
struct Event{
	int id, dx, dy;
	bool operator<(const Event& rhs) const{
		if(id != rhs.id) return id < rhs.id;
		if(dx != rhs.dx) return dx < rhs.dx;
		return dy < rhs.dy;
	}
};

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
ll bino[203][203];
ll pow2[203];
Point ps[203];
int N;
ll ans;
map<Event, bool> check;
ll calcScore(int n){
	ll ret = 0;
	for(int i = 3; i <= n; i++) {
		ret = (ret + bino[n][i] * pow2[n - i]) % mod;
	}
	return ret;
}
int main() {
	fastio();
	for(int i = 0 ; i <= 200; i++) bino[i][0] = 1;
	for(int i = 1; i <= 200; i++){
		for(int j = 1; j <= i; j++){
			bino[i][j] = (bino[i - 1][j] + bino[i - 1][j - 1]) % mod;
		}
	}
	pow2[0] = 1;
	for(int i = 1; i <= 200; i++) pow2[i] = pow2[i - 1] * 2 % mod;

	cin >> N;
	ans = calcScore(N);

	for(int i = 0 ; i < N; i++) {
		int x, y;
		cin >> x >> y;
		ps[i] = Point{x, y};
	}
	sort(ps, ps + N);
	for(int i = 0 ; i < N; i++){
		auto u = ps[i];
		for(int j = i + 1; j < N; j++){
			auto v = ps[j];
			int dx = u.x - v.x;
			int dy = u.y - v.y;
			int g = gcd(abs(dx), abs(dy));
			dx /= g, dy /= g;
			if(check[Event{j, dx, dy}] || check[Event{i, dx, dy}]) continue;
			check[Event{i, dx, dy}] = true;
			int cnt = 0;
			for(int k = 0; k < N; k++){
				if(k == i) continue;
				auto w = ps[k];
				int dx2 = u.x - w.x;
				int dy2 = u.y - w.y;
				int g2 = gcd(abs(dx2), abs(dy2));
				dx2 /= g2, dy2 /= g2;
				if(dx == dx2 && dy == dy2) {
					cnt++;
					check[Event{k, dx2, dy2}] = true;
				}
			}
			ans = (ans - calcScore(cnt) + mod) % mod;
		}
	}
	cout << ans;
	return 0;
}