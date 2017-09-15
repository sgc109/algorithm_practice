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
int N;
ll A[100003];
ll psum[100003];
stack<pair<int, int> > stk;
int main() {
	fastio();
	cin >> N;
	A[N + 1] = -1;
	ll ans = 0;
	pair<int,int> ansP;
	for(int i = 1; i <= N + 1; i++){
		cin >> A[i];
		psum[i] = psum[i - 1] + A[i];
		while(!stk.empty() && stk.top().first > A[i]){
			auto p = stk.top();
			stk.pop();
			int h = p.first;
			int prv = stk.empty() ? 0 : stk.top().second;
			ll upd = (psum[i - 1] - psum[prv]) * h;
			if(ans <= upd) {
				ans = upd;
				ansP = {prv, i - 1};
			}
		}
		stk.push({A[i], i});
	}
	cout << ans << '\n' << ansP.first + 1 << ' ' << ansP.second;
	return 0;
}