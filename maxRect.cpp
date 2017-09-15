#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
int psum[103][103];
int pane[103][103];
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(psum,0,sizeof(psum));
		cin >> N;
		for(int i = 1 ; i <= N; i++){
			for(int j = 1; j <= N; j++){
				cin >> pane[i][j];
			}
		}

		for(int i = 1 ; i <= N; i++){
			for(int j = 1; j <= N; j++){
				psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + pane[i][j];
			}
		}

		int ans = -inf;
		for(int x1 = 1; x1 <= N; x1++){
			for(int x2 = x1; x2 <= N; x2++){
				for(int y1 = 1; y1 <= N; y1++){
					for(int y2 = y1; y2 <= N; y2++){
						ans = max(ans, psum[y2][x2] - psum[y1-1][x2] - psum[y2][x1-1] + psum[y1-1][x1-1]);
					}
				}
			}
		}
		cout << "Case #" << t << endl;
		cout << ans << endl;
	}
	return 0;
}