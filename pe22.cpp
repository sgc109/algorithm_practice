#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

vector<string> names;
int main() {
	string S;
	cin >> S;
	stringstream ss(S);
	string s;
	while(getline(ss, s, ',')){
		string s2 = s.substr(1, sz(s) - 2);
		names.pb(s2);
	}
	sort(all(names));
	ll ans = 0;
	for(int i = 1; i <= sz(names); i++){
		int sum = 0;
		for(char c : names[i - 1]) sum += c - 'A' + 1;
		ans += sum * i;
	}
	cout << ans;
	return 0;
}