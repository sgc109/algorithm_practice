#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
int pane[303][303];
ll dp[303][303];
int lastX, lastY;
int inRange(int x, int y){
	return 0 <= x && x <= lastX && 0 <= y && y <= lastY;
}
ll go(int x, int y){
	ll& cache = dp[x][y];
	if(cache != -1) return cache;
	cache = max(0,M-(x+y))*pane[x][y];
	ll add = 0;
	if(inRange(x,y+1)) add = max(add, go(x,y+1));
	if(inRange(x+1,y)) add = max(add, go(x+1,y));
	return cache += add;
}
int main() {
	memset(dp,-1,sizeof(dp));
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		int a,b;
		cin >> a >> b;
		lastX = max(lastX, a);
		lastY = max(lastY, b);
		pane[a][b]++;
	}

	cout << go(0,0);

	return 0;
}
