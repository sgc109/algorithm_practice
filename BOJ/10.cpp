#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, M, K, B, Z;
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < M;
}
int cnt[1000003];
int backup[1000003];	
int** dist;
queue<pair<int,int> > q;
int main() {
	scanf("%d%d%d%d%d",&N,&M,&K,&B,&Z);
	dist = (int**)malloc(sizeof(int*) * N);
	for(int i = 0 ; i < N; i++) dist[i] = (int*)malloc(sizeof(int) * M);
	for(int i = 0 ; i < N; i++) for(int j = 0 ; j < M; j++) dist[i][j] = -1;
	for(int i = 0 ; i < K; i++){
		int r,c;
		scanf("%d%d",&r,&c);
		r--, c--;
		q.push({r, c});
		dist[r][c] = 0;
	}
	int maxD = 0;
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		int ci = p.first;
		int cj = p.second;
		for(int k = 0 ; k < 4; k++){
			int ni = ci + "1021"[k] - '1';
			int nj = cj + "0112"[k] - '1';
			if(!inRange(ni, nj) || dist[ni][nj] != -1) continue;
			dist[ni][nj] = dist[ci][cj] + 1;
			cnt[dist[ni][nj]]++;
			maxD = max(maxD, dist[ni][nj]);
			q.push({ni, nj});
		}
	}
	for(int i = 0; i <= maxD; i++) backup[i] = cnt[i];
	int ans1 = 0;
	int t = 0;
	int cur = Z;
	for(int i = maxD; t < i;) {
		if(cnt[i] > cur){
			cnt[i] -= cur;
			ans1 += cur;
			cur = Z;
			t++;
		}
		else {
			cur -= cnt[i];
			ans1 += cnt[i];
			i--;
		}
	}
	printf("%d\n",ans1);

	for(int i = 0 ; i <= maxD; i++) cnt[i] = backup[i];

	int ans2 = 0;
	t = 0;
	int pos = 1;
	cur = Z;
	while(t < maxD && pos <= maxD) {
		if(t == pos) pos = t + 1;
		if(cnt[pos] > cur){
			cnt[pos] -= cur;
			ans2 += cur;
			cur = Z;
			t++;
		}
		else {
			cur -= cnt[pos];
			ans2 += cnt[pos];
			pos++;
		}
	}

	printf("%d\n",ans2);

	return 0;
}