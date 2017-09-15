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
char pane[3003][3003];
int main() {
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i < N; i++) cin >> pane[i];
	int t = inf;
	for(int j = 0 ; j < M; j++){
		int last = -1;
		for(int i = 0 ; i < N; i++){
			if(pane[i][j] == 'X') last = max(last, i);
			else if(pane[i][j] == '#'){
				if(last == -1) break;
				t = min(t, i - last - 1);
			}
		}
	}
	for(int j = 0 ; j < M; j++){
		for(int i = N - 1; i >= 0; i--){
			if(pane[i][j] == 'X') pane[i + t][j] = 'X', pane[i][j] = '.';
		}
	}
	for(int i = 0 ; i < N; i++) cout << pane[i] << '\n';
	return 0;
}