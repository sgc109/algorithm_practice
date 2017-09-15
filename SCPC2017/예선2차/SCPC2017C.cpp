#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Query{
	int b, l, r;
	bool operator<(const Query& rhs) const{
		return r < rhs.r;
	}
};
vector<int> calcDivs(int x){
	vector<int> ret;
	for(int i = 1; i * i <= x; i++){
		if(x % i) continue;
		ret.pb(i);
		if(i * i != x) ret.pb(x / i);
	}
	return ret;
}
int A[100003];
int last[1000003];
int T, N, M;
vector<Query> qs;
int main() {
	fastio();
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(last,-1,sizeof(last));
		qs.clear();
		cin >> N >> M;
		for(int i = 0 ; i < N; i++) cin >> A[i];
		for(int i = 0 ; i < M; i++){
			int b, l, r;
			cin >> b >> l >> r;
			l--, r--;
			qs.pb(Query{b, l, r});
		}
		sort(all(qs));
		int prv = -1;
		int ans = 0;
		for(auto q : qs){
			int b = q.b;
			int l = q.l;
			int r = q.r;
			for(int i = prv + 1; i <= r; i++){
				int x = A[i];
				vector<int> divs = calcDivs(x);
				for(int dv : divs){
					last[dv] = i;
				}
			}
			vector<int> divs = calcDivs(b);
			for(int dv : divs){
				if(last[dv] < l) ans++;
			}
			prv = r;
		}
		cout << "Case #" << t << '\n';
		cout << ans << '\n';
	}
	return 0;
}