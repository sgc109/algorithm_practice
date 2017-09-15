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

int T;
string S;
bool go(string s){
	if(sz(s) == 0) return true;
	int prv = 0;
	int cnt = 1;
	vector<pair<int,int> > v;
	for(int i = 0 ; i < sz(s); i++){
		if(s[i] != s[i + 1]) {
			if(cnt > 1) v.pb({prv, i});
			prv = i + 1;
			cnt = 1;
		}
		else cnt++;
	}
	for(auto p : v){
		string tmp = s;
		tmp.erase(tmp.begin() + p.first, tmp.begin() + p.second + 1);
		if(go(tmp)) return true;
	}
	return false;
}
int main() {
	fastio();
	cin >> T;
	while(T--){
		cin >> S;
		cout << (go(S) ? 1 : 0) << '\n';

	}
	return 0;
}