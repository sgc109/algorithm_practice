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

int N, M;
unordered_map<ll, int> mp;
ll hashf(string& s){
	ll ret = 0;
	for(int i = 0 ; i < sz(s); i++){
		ret = ret * 26 + s[i] - 'a';
	}
	return ret;
}
int main() {
	fastio();
	cin >> N >> M;
	while(N--){
		string s;
		cin >> s;
		mp[hashf(s)] = 1;
	}

	int ans = 0;
	while(M--){
		string s;
		cin >> s;
		ans += mp[hashf(s)];
	}

	cout << ans;
	return 0;
}