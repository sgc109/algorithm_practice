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

int N, M;
int pane[1003][1003];
int h[1003][1003];
stack<int> s;
int main() {
	fastio();
	while(1){
		cin >> N >> M;
		if(!N && !M) break;
		for(int i = 1 ; i <= N; i++){
			for(int j = 1 ; j <= M; j++){
				cin >> pane[i][j];
			}
		}
		for(int j = 1 ; j <= M; j++){
			for(int i = 1 ; i <= N; i++){
				h[i][j] = pane[i][j] ? h[i - 1][j] + 1 : 0;
			}
		}
		int ans = 0;
		for(int i = 1; i <= N; i++){
			int tans = 0;
			for(int j = 1 ; j <= M + 1; j++){
				while(!s.empty() && h[i][s.top()] >= h[i][j]) {
					auto p = s.top();
					s.pop();
					tans = max(tans, h[i][p] * (s.empty() ? j - 1: j - s.top() - 1));
				}
				if(j <= M) s.push(j);
			}
			ans = max(ans, tans);
		}

		cout << ans << '\n';
	}
	return 0;
}