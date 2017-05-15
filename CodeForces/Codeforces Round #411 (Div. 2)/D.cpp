#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

string str;
long long mod[1000003];
int main() {
	mod[0] = 1;
	for(int i = 1; i < 1000003; i++) mod[i] = (mod[i-1]*2)%MOD;
	cin >> str;

	int cnt = 0;
	long long ans = 0;
	char prev = 'z';
	for(int i = 0 ; i < str.size(); i++){
		if(str[i] == 'a') cnt++;
		else ans = (ans + mod[cnt] - 1) % MOD;
		prev = str[i];
	}
	printf("%lld", ans);
	

	return 0;
}
