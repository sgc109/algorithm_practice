#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int degree[26];
int n;
int main() {
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		string s;
		cin >> s;
		degree[s[0]-'a']++;
		degree[s.back()-'a']++;
	}
	int odd = 0;
	for(int i = 0 ; i < 26; i++){
		if(degree[i]%2) odd++;
	}
	if(odd == 2 || odd == 0) cout << "YES";
	else cout << "NO";
	return 0;
}