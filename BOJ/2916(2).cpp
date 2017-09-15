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

int N, K;
int poss[363];
int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
int main() {
	fastio();
	cin >> N >> K;
	queue<int> q;
	for(int i = 0 ; i < N; i++) {
		int a;
		cin >> a;
		poss[a] = 1;
		q.push(a);
	}
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0 ; i <= 360; i++){
			if(!poss[i]) continue;
			for(int j = 0 ; j <= 360; j++){
				if(poss[j]) continue;
				int g = gcd(gcd(cur, i), j);
				if(!g) {
					poss[j] = 1;
					q.push(j);
					break;
				}
				int gg = gcd(cur / g, i / g);
				if(gg == 1) {
					poss[j] = 1;
					q.push(j);
				}
			}
		}
	}
	for(int i = 0 ; i < K; i++){
		int gak;
		cin >> gak;
		if(poss[gak]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}