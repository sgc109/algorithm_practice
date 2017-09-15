#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, K, Q;
pair<int, char> in[10003];
int check[26];
int main() {
	cin >> N >> K >> Q;
	Q--;
	for(int i = 0 ; i < K; i++){
		int a;
		char b;
		cin >> a >> b;
		in[i] = {a, b};
	}
	if(in[Q].first == 0) return !printf("-1");

	for(int i = K - 1; in[i].first >= in[Q].first && i >= 0; i--){
		check[in[i].second - 'A'] = 1;
	}
	for(int i = 1 ; i < N; i++) if(!check[i]) printf("%c ", i + 'A');
	return 0;
}