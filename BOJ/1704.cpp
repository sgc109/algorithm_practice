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
int in[20][20];
int pane[20][20];
int press[20][20];
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}
bool poss(){
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			if(pane[i][j]) return false;
		}
	}
	return true;
}
int main() {
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i < N; i++) {
		for(int j = 0 ; j < M; j++) {
			cin >> in[i][j];
		}
	}
	int ok = 0;
	for(int mask = 0 ; mask < (1 << M); mask++){
		memset(press,0,sizeof(press));
		for(int i = 0 ; i < N; i++) {
			for(int j = 0 ; j < M; j++){
				pane[i][j] = in[i][j];
			}
		}
		for(int i = 0 ; i < M; i++){
			if(~mask & (1 << i)) continue;
			press[0][i] = 1;
			for(int k = 0; k < 5; k++){
				int ni = "01121"[k] - '1';
				int nj = "11210"[k] - '1' + i;
				if(!inRange(ni, nj)) continue;
				pane[ni][nj] ^= 1;
			}
		}
		
		for(int i = 1; i < N; i++){
			for(int j = 0 ; j < M; j++){
				if(!pane[i - 1][j]) continue;
				press[i][j] = 1;
				for(int k = 0; k < 5; k++){
					int ni = "01121"[k] - '1' + i;
					int nj = "11210"[k] - '1' + j;
					if(!inRange(ni, nj)) continue;
					pane[ni][nj] ^= 1;
				}
			}	
		}
		if(poss()) {
			ok = 1;
			break;
		}
	}
	if(ok){
		for(int i = 0 ; i < N; i++){
			for(int j = 0 ; j < M; j++){
				cout << press[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else cout << "IMPOSSIBLE";
	return 0;
}