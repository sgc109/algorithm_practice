#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct point{
	int x,y;
};
int N;
point points[5003];
point A,B;
int D;
int distA[5003], distB[5003];
int poww(int x){return x*x;}
int dist(point& a, point& b){return poww((a.x - b.x)) + poww(a.y - b.y);}
bool cmp(point& a, point& b){return dist(A,a) < dist(A,b);}

int main() {
	cin >> N;
	for(int i = 0 ; i < N; i++){
		int x,y;
		cin >> x >> y;
		points[i] = point{x,y};
	}
	D = 0;
	for(int i = 0 ; i < N; i++){
		for(int j = i+1; j < N; j++){
			int d = dist(points[i], points[j]);
			if(D < d) A = points[i], B = points[j], D = d;
		}
	}

	sort(points, points+N, cmp);

	for(int i = N-1; i >= 0 ; i--){
		int d = distB[i+1];
		for(int j = i+1 ; j < N; j++){
			d = max(d, dist(points[i], points[j]));
		}
		distB[i] = d;
	}
	
	for(int i = 0 ; i < N; i++){
		int d = i > 0 ? distA[i-1] : 0;
		for(int j = 0; j < i; j++){
			d = max(d, dist(points[i], points[j]));
		}
		distA[i] = d;
	}
	double ans = distB[0];

	for(int i = 0 ; i < N; i++){
		ans = min(ans, sqrt(distA[i]) + sqrt(distB[i+1]));
	}

	cout.precision(10);
	cout << ans << endl;

	return 0;
}
