#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

struct point{int x, y;};
int N, M, L, K;
point points[103];
bool inRange(int cy, int cx, int y, int x){
	return cy <= y && y <= cy + L && cx <= x && x <= cx + L;
}
int main() {
	fastio();
	cin >> N >> M >> L >> K;
	for(int i = 0 ; i < K; i++){
		cin >> points[i].y >> points[i].x;
	}
	int ans = 0;
	for(int i = 0; i < K; i++){
		for(int j = 0 ; j < K; j++){
			int cy = points[i].y;
			int cx = points[j].x;
			int cnt = 0;
			for(int k = 0 ; k < K; k++){
				if(inRange(cy, cx, points[k].y, points[k].x)) cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	cout << K - ans;
	return 0;
}