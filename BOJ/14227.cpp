#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int A, B, C, D;
int main() {
	// fastio();
	cin >> A >> B >> C >> D;
	if(A == C && B == D) return !printf("0");
	if(A >= C || B >= D) return !printf("-1");
	if(A <= B != C <= D) return !printf("-1");
	int diff1 = B - A, diff2 = D - C;
	if((!diff1 && diff2) || (diff1 && !diff2)) return !printf("-1");
	if(abs(diff1) > abs(diff2)) return !printf("-1");
	int cnt = -1;
	if(diff1){
		int mult = diff2 / diff1;
		if(mult != (mult & -mult)) return !printf("-1");
		while(mult) mult /= 2, cnt++;
	}
	else cnt = inf;
	int ans = 0;
	while(A < C && B < D){
		// printf("A : %d, B : %d, C : %d, D : %d, ans : %d\n", A, B, C, D, ans);
		if(C % 2 != D % 2 || !cnt) {
			if(C - A != D - B) return !printf("-1");
			return !printf("%d", C - A + ans);
		}
		if(C % 2) C--, D--;
		else C /= 2, D /= 2, cnt--;
		ans++;
	}
	if(A == C && B == D) cout << ans;
	else cout << -1;
	return 0;
}