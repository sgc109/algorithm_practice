#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
ll check[1000003];
int main() {
	freopen("output.txt","w",stdout);
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(check,0,sizeof(check));
		cin >> N >> M;
		for(int i = 0 ; i < M; i++){
			int a,b;
			cin >> a >> b;
			b--;
			check[a]--;
			check[b+1]++;
		}
		int sum = 0;
		int ans = 0;
		for(int i = 1; i < N; i++){
			sum += check[i];
			if(sum >=0) ans++;
		}
		cout << "Case #" << t << "\n" << ans+1 << "\n";
	}
	return 0;
}
