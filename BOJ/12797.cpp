#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
char pane[103][103];
int dist[103][103];
int isUpper(char c){
	return 'A' <= c && c <= 'Z';
}
int alpha2num(char c){
	if(isUpper(c)) return c - 'A';
	return c - 'a';
}
int inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < N;
}
int main() {
	freopen("output.txt","w",stdout);
	while(cin >> N){
		for(int i = 0 ; i < N; i++) cin >> pane[i];
		int ans = inf;
		for(int i = 0 ; i < (1<<10); i++){
			if(isUpper(pane[0][0]) != (((1<<alpha2num(pane[0][0])) & i) != 0)) continue;
			memset(dist,-1,sizeof(dist));
			queue<pair<int,int> > q;
			q.push({0,0});
			dist[0][0] = 0;
			while(!q.empty() && dist[N-1][N-1] == -1){
				int hereI = q.front().first;
				int hereJ = q.front().second;
				q.pop();
				for(int k = 0 ; k < 4; k++){
					int ni = hereI + "2110"[k] - '1';
					int nj = hereJ + "1201"[k] - '1';
					if(isUpper(pane[ni][nj]) != (((1<<alpha2num(pane[ni][nj])) & i) != 0)) continue;
					if(!inRange(ni,nj) || dist[ni][nj] != -1) continue;
					dist[ni][nj] = dist[hereI][hereJ] + 1;
					q.push({ni,nj});
				}
			}
			if(dist[N-1][N-1] == -1) continue;
			ans = min(ans, dist[N-1][N-1] + 1);
		}
		if(ans == inf) ans = -1;
		cout << ans << endl;
	}
	return 0;
}