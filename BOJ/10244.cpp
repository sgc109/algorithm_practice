#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, T;
int ans[103], st[103];
int g[103][103];
int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
int main() {
	fastio();
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++) {
			g[i][j] = gcd(i, j);
		}
	}
	while(1){
		memset(ans,0,sizeof(ans));
		memset(st,0,sizeof(st));
		cin >> N;
		if(!N) break;
		for(int i = 0 ; i < N; i++){
			int a;
			cin >> a;
			vector<int> push;
			for(int i = 1; i <= 100; i++) if(st[i]) push.pb(gcd(i, a));
			memset(st,0,sizeof(st));
			for(auto num : push) st[num] = 1;
			st[a] = 1;
			for(int i = 1; i <= 100; i++) if(st[i]) ans[i] = 1;
		}
		int cnt = 0;
		for(int i = 1; i <= 100; i++) cnt += ans[i];
		cout << cnt << '\n';
	}
	return 0;
}