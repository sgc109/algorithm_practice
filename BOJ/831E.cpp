#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

set<int> st;
vector<int> nums;
vector<int> idxs[100003];
int N, a;
int t[800003];
void update(int x, int v){
	while(x <= N){
		t[x] += v;
		x += x & -x;
	}
}
int query(int x){
	int ret = 0;
	while(x > 0){
		ret += t[x];
		x -= x & -x;
	}
	return ret;
}
int main() {
	fastio();
	cin >> N;
	for(int i = 1 ; i <= N; i++){
		cin >> a;
		idxs[a].push_back(i);
		st.insert(a);
		update(i, 1);
	}
	int pos = 0;
	ll ans = 0;
	nums.assign(all(st));
	for(int i = 0 ; i < sz(nums); i++){
		int cur = nums[i];
		int f = idxs[cur].front();
		int b = idxs[cur].back();
		if(f < pos && pos < b) {
			int p = lower_bound(all(idxs[cur]), pos) - idxs[cur].begin();
			ans += query(N) - query(pos) + query(idxs[cur][p - 1]);
			pos = idxs[cur][p - 1];
		}
		else if(pos <= f) {
			ans += query(b) - query(pos);
			pos = b;
		}
		else {
			ans += query(b) + query(N) - query(pos);
			pos = b;
		}
		for(int e : idxs[cur]) update(e, -1);
	}

	cout << ans << "\n";
	
	return 0;
}