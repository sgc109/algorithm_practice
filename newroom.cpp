#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
int cnt2[103][103];
int cnt3[103][103];
int dist[103][103];

struct chunk{
	int cnt2, cnt3;
	int posI, posJ;
	bool operator<(const chunk& rhs) const{
		return min(cnt2, cnt3) < min(rhs.cnt2, rhs.cnt3);
	}
};
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		memset(cnt2,0,sizeof(cnt2));
		memset(cnt3,0,sizeof(cnt3));
		memset(dist,-1,sizeof(dist));

		cin >> N;
		for(int i = 1 ; i <= N; i++){
			for(int j = 1; j <= N; j++){
				int tmp;
				cin >> tmp;
				for(; tmp % 3 == 0; tmp/=3) cnt3[N+1-i][j]++;
				for(; tmp % 2 == 0; tmp/=2) cnt2[N+1-i][j]++;
			}
		}

		priority_queue<chunk> pq;
		pq.push(chunk{cnt2[1][1],cnt3[1][1],1,1});
		dist[1][1] = min(cnt2[1][1], cnt3[1][1]);
		while(!pq.empty()){
			auto p = pq.top();
			pq.pop();
			int hereI = p.posI;
			int hereJ = p.posJ;
			int c2 = p.cnt2;
			int c3 = p.cnt3;
			if(dist[hereI][hereJ] > min(c2, c3)) continue;
			for(int k = 0 ; k < 2; k++){
				int thereI = hereI + "12"[k]-'1';
				int thereJ = hereJ + "21"[k]-'1';
				if(thereI > N || thereJ > N) continue;
				int nc2 = c2+cnt2[thereI][thereJ];
				int nc3 = c3+cnt3[thereI][thereJ];
				if(dist[thereI][thereJ] >= min(nc2, nc3)) continue;
				dist[thereI][thereJ] = min(nc2, nc3);
				pq.push({nc2, nc3, thereI, thereJ});
			}
		}

		cout << "Case #" << t << "\n" << dist[N][N] << "\n";
	}

	return 0;
}
