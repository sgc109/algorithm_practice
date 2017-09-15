#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+9;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
int main() {
	scanf("%d", &N);
	if(N == 1) return !printf("0");
	ll ans = 2;
	for(int i = 0 ; i < N - 2; i++) ans = (ans * 3) % mod;
	printf("%lld", ans);
	return 0;
}