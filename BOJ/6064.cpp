#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

ll xGCD(ll a, ll b, ll& x, ll& y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	ll x1, y1;
	int ret = xGCD(b, a % b, x1, y1);
	x = y1, y = x1 - (a / b) * y1;
	return ret;
}

ll chinese(vector<ll>& mods, vector<ll>& remains) {
	ll lcm = 1;
	for (ll num : mods) lcm *= num;
	ll ret = 0;
	ll N = 1;
	for (ll num : mods) N *= num;
	for (int i = 0; i < (int)mods.size(); i++) {
		ll n = mods[i];
		ll x, y;
		xGCD(n, N / n, x, y);
		if (y < 0) y %= N, y += N;
		ret = (ret + N / n * y % lcm * remains[i] % lcm) % lcm;
	}
	return ret;
}

bool check(vector<ll>& mods, vector<ll>& remains) {
	int n = (int)mods.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || remains[i] < remains[j]) continue;
			ll trash;
			ll left = xGCD(mods[i], mods[j], trash, trash);
			ll right = remains[i] - remains[j];
			if (right % left) return false;
		}
	}
	return true;
}

void addMap(map<ll, pair<ll, ll> >& mp, ll idx, pair<ll, ll> pr) {
	if (mp.find(idx) != mp.end() && mp[idx].first < pr.first) mp.erase(idx);
	if (mp.find(idx) == mp.end()) mp[idx] = pr;
}
void makeVectors(vector<ll>& prevMods, vector<ll>& prevRem, vector<ll>& mods, vector<ll>& remains) {
	map<ll, pair<ll, ll> > mp;
	for (int i = 0; i < (int)prevMods.size(); i++) {
		ll back = prevMods[i];
		for (ll j = 2; j * j <= back; j++) {
			ll prev = back;
			while (back % j == 0) back /= j;
			addMap(mp, j, { prev / back, prevRem[i] });
		}
		if (back != 1) addMap(mp, back, { back, prevRem[i] });
	}
	for (auto it : mp) {
		ll md = it.second.first;
		ll rem = it.second.second;
		rem %= md;
		mods.push_back(md);
		remains.push_back(rem);
	}
}

ll M, N, x, y, T;
int main() {
	fastio();
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;
		vector<ll> prevMods({ M, N });
		vector<ll> prevRem({ x - 1, y - 1 });
		if (!check(prevMods, prevRem)) {
			cout << -1 << endl;
			continue;
		}
		vector<ll> mods, remains;
		makeVectors(prevMods, prevRem, mods, remains);
		ll ret = chinese(mods, remains);
		cout << ret + 1 << endl;
	}
	return 0;
}