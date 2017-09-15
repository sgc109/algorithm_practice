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

int N;
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < N;
}
string S[53];
int col[53][53];
int ans;
int main() {
	fastio();
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> S[i];
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			if(S[i][j] == '-') continue;
			int check[11];
			memset(check,0,sizeof(check));
			for(int k = 0 ; k < 6; k++){
				int ni = i + "001221"[k] - '1';
				int nj = j + "122100"[k] - '1';
				if(!inRange(ni, nj)) continue;
				check[col[ni][nj]] = 1;
			}
			int k;
			for(k = 1; k <= 10; k++) if(!check[k]) break;
			col[i][j] = k;
			ans = max(ans, k);
		}
	}

	cout << ans;

	return 0;
}