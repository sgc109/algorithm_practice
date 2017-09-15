#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

string S, s;
int main() {
	while(cin >> s) S += s;
	
	int mult = 1;
	for(int i = 0 ; i < 5; i++) mult *= S[i] - '0';
	
	int ans = 0;
	for(int i = 5; i <= sz(S); i++) {
		ans = max(ans, mult);
		if(i == sz(S)) break;
		if(S[i - 5] != '0') mult /= S[i - 5] - '0';
		if(S[i] != '0') mult *= (S[i] - '0');
	}

	cout << ans;
	return 0;
}