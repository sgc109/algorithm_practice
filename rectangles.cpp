#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct Point{
	ll x,y;
};
struct Rect{
	Point p1, p2;
};
int T,K;
ll N,M;
Rect rects[5003];
int maxLen[5003];
bool cmp(Rect& A, Rect& B){
	ll w1 = (A.p2.x - A.p1.x) * (A.p2.y - A.p1.y);
	ll w2 = (B.p2.x - B.p1.x) * (B.p2.y - B.p1.y);
	return w1 < w2;
}
bool contain(Rect& A, Rect& B){
	bool c1 = A.p1.x <= B.p1.x && B.p2.x <= A.p2.x;
	bool c2 = A.p1.y <= B.p1.y && B.p2.y <= A.p2.y;
	return c1 && c2;
}
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> N >> M >> K;
		for(int i = 0 ; i < K; i++){
			ll x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			rects[i] = Rect{Point{x1,y1}, Point{x2,y2}};
		}

		sort(rects, rects+K, cmp);

		int ans = 0;
		for(int i = 0 ; i < K; i++){
			int maxl = 0;
			for(int j = 0 ; j < i; j++){
				if(contain(rects[i], rects[j])) maxl = max(maxl, maxLen[j]);
			}
			maxLen[i] = maxl + 1;
			ans = max(ans, maxLen[i]);
		}

		cout << "Case #" << t << endl;
		cout << ans << endl;
	}

	return 0;
}
