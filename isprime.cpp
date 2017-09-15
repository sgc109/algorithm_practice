#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int main() {
	ll N;
	cin >> N;
	int ok = 1;
	for(ll i = 2 ; i * i <= N; i++){
		if(N % i == 0){
			ok = 0;
			break;
		}
	}	
	if(ok) printf("YES");
	else printf("NO");
	return 0;
}