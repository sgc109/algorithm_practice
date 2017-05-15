#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
int main() {
	scanf("%d",&N);
	string ans;
	for(int i = 0 ; i < N/2; i++){
		if(i%2) ans += "aa";
		else ans += "bb";
	}
	if(N%2){
		if((N/2)%2) ans += "a";
		else ans += "b";
	}
	cout << ans;
	return 0;
}
