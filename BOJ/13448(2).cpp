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

struct Prob{
	ll M, P, R;
	bool operator<(const Prob& rhs) const{
		return P * rhs.R > R * rhs.P;
	}
};
int N;
ll T;
Prob probs[53];
ll dp[53][100003];
ll go(int pos, ll rest){
	if(pos == N) return 0;
	ll& cache = dp[pos][rest];
	if(cache != -1) return cache;
	ll ret = go(pos + 1, rest);
	auto p = probs[pos];
	if(p.R <= rest) ret = max(ret, p.M - (T - rest + p.R) * p.P + go(pos + 1, rest - p.R));
	return cache = ret;
}
int main() {
	fastio();
	memset(dp,-1,sizeof(dp));
	cin >> N >> T;
	for(int i = 0 ; i < N; i++) cin >> probs[i].M;
	for(int i = 0 ; i < N; i++) cin >> probs[i].P;
	for(int i = 0 ; i < N; i++) cin >> probs[i].R;
	sort(probs, probs + N);
	cout << go(0, T);
	return 0;
}