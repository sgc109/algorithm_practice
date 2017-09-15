#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M,K,P;
int dist[103][103];
void floyd(){
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		memset(dist,0x3c,sizeof(dist));
		cin >> N >> M >> K;
		for(int i = 0 ; i < M; i++){
			int a,b,c;
			cin >> a >> b >> c;
			dist[b][a] = dist[a][b] = c;
		}
		floyd();
		cin >> P;
		int ans = 0;
		for(int i = 0 ; i < P; i++){
			int a,b;
			cin >> a >> b;
			if(dist[a][b] > K) ans++;
		}
		cout << "Case #" << t << "\n" << ans << endl;
	}	
	return 0;
}
	