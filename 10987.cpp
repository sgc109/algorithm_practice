#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

map<char ,int> mp;
int main() {
	string str;
	string str2 = "aeiou";
	cin >> str;
	for(int i = 0 ; i < str.size(); i++) mp[str[i]]++;
	int ans = 0 ;
	for(auto s : str2) ans += mp[s];
	printf("%d",ans);
	return 0;	
}
