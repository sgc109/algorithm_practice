#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

string pos;
bool dp1[1000003][3], dp2[1000003][3];
int T, N;
int main() {
	fastio();
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		cin >> N;
		cin >> pos;
		for(int i = 0 ; i < 3; i++) dp1[0][i] = dp2[0][i] = true;
		for(int i = 1; i <= N; i++) {
			for(int j = 0 ; j < 3; j++){
				if(pos[i - 1] - 'A' == j) dp1[i][j] = dp2[i - 1][j];
				else if(pos[i -1] - 'A' == ((j + 1) % 3)) dp1[i][j] = dp2[i - 1][(j + 2) % 3];
				else dp1[i][j] = false;

				if(pos[i - 1] - 'A' == j) dp2[i][j] = dp2[i -1 ][j];
				else if(pos[i - 1] - 'A' == ((j + 1) % 3)) dp2[i][j] = dp1[i - 1][(j + 2) % 3];
				else if(pos[i - 1] - 'A' == ((j + 2) % 3)) dp2[i][j] = dp2[i - 1][j];
				else dp2[i][j] = false;
			}
		}
		cout << "Case #" << t << '\n';
		cout << (dp1[N][0] ? "YES" : "NO") << '\n';
	}
	return 0;
}