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
void NO(){
	cout << -1;
	exit(0);
}
int main() {
	fastio();
	string S;
	cin >> S;
	int N = sz(S);
	for(int i = 0 ; i < N; i++) cnt[S[i] - 'A']++;
	string ans;
	if(cnt[2] > 1){
		if(cnt[0] < cnt[2] - 1 || cnt[1] < cnt[2] - 1) NO();
		if(cnt[1] > 2 * cnt[2]) NO();
		cnt[1] -= cnt[2] - 1, cnt[0] -= cnt[2] - 1;
		for(int i = 0; i < cnt[2] - 1; i++) {
			if(cnt[1]) ans += "CBAB", cnt[1]--;
			else ans += "CBA";
		}
		ans += 'C';
		if(cnt[1]) ans = 'B' + ans, cnt[1]--;
		if(cnt[1]) ans += 'B', cnt[1]--;
		while(cnt[0]) ans += 'A', cnt[0]--;
	}
	else {
		queue<char> q;
		while(cnt[0]) q.push('A'), cnt[0]--;
		while(cnt[2]) q.push('C'), cnt[2]--;
		while(cnt[1]){
			if(cnt[1] > 1 && q.empty()) NO();
			ans += 'B';
			if(!q.empty()) ans += q.front(), q.pop();;
			cnt[1]--;
		}
		while(!q.empty()) ans += q.front(), q.pop();
	}
	cout << ans;
	return 0;
}