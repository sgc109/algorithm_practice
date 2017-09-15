#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int chk[100000];
int N;
int main() {
	cin >> N;
	int ans = 0;
	for(int i = 0 ; i < N; i++) {
		int a;
		cin >> a;
		if(chk[a]) ans++;
		else chk[a] = 1;
	}

	printf("%d",ans);

	return 0;
}
