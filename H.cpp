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

int arr[13][13][13];
int dp[13][13][13];

int getAnswer(int F, int Y, int X){
	if(F == 0 || Y > 10 || X > 10) return 0;
	int &res = dp[F][Y][X];
	if(res != -1) return res;
	res = arr[F][Y][X];
	res += max({getAnswer(F, Y, X + 1), getAnswer(F, Y + 1, X), getAnswer(F - 1, Y, X)});
	return res;
}

int main() {
	fastio();
	freopen("commandos.in", "r", stdin);
	int T;
	cin >> T;
	while(T--){
		memset(dp, -1, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		int N;
		cin >> N;
		for(int i = 0; i < N; i++){
			int F, Y, X, H;
			cin >> F >> Y >> X >> H;
			arr[F][Y][X] = H;
		}
		cout << getAnswer(10, 1, 1) << "\n";
	}
	return 0;
}