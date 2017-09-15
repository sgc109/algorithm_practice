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

int cnt[3];
int main() {
	fastio();
	string S;
	cin >> S;
	for(int i = 0 ; i < sz(S); i++) cnt[S[i] - 'A']++;
	string ans;
	if(cnt[2]){
		if(cnt[0] + min(cnt[2] - 1, cnt[1]) < 2 * (cnt[2] - 1)) return !printf("-1");
		while(cnt[2]){
			cnt[2]--;
			ans += 'C';
			if(!cnt[2]) break;
			if(cnt[1]) cnt[1]--, ans += 'B';
			else cnt[0]--, ans += 'A';
			cnt[0]--, ans += 'A';
		}
		string tmp = ans;
		ans = ans[0];
		for(int i = 1 ; i < sz(tmp); i++){
			if(cnt[1] && tmp[i - 1] == 'A' && tmp[i] == 'C') {
				cnt[1]--, ans += 'B';
			}
			ans += tmp[i];
		}
		if(cnt[1]) ans = 'B' + ans, cnt[1]--;
		if(cnt[1]) ans += 'B', cnt[1]--;
	}
	else if(cnt[1]) cnt[1]--, ans += 'B';
	if(cnt[1] > cnt[0]) return !printf("-1");
	while(cnt[1]){
		ans += 'A', cnt[0]--;
		ans += 'B', cnt[1]--;
	}
	while(cnt[0]) ans += 'A', cnt[0]--;
	cout << ans;
	return 0;
}