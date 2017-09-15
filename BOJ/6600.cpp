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
const double PI = acos(-1);
struct point{
	double x, y;
	point operator-(const point& rhs) const{
		return point{x - rhs.x, y - rhs.y};
	}
	point operator+(const point& rhs) const{
		return point{x + rhs.x, y + rhs.y};
	}
	point operator*(double k) const {
		return point{x * k, y * k};
	}
	double size(){
		return x * x + y * y;
	}
};
point ps[3];
double pow2(double x){
	return x * x;
}
double dist(point a, point b){
	return pow2(a.x - b.x) + pow2(a.y - b.y);
}
bool equal(double a, double b){
	return fabs(a - b) <= 1e-9;
}
int main() {
	fastio();
	cout.precision(2);
	cout << fixed;
	while(cin >> ps[0].x >> ps[0].y){
		for(int i = 1 ; i < 3; i++){
			double xx, yy;
			cin >> xx >> yy;
			ps[i] = point{xx, yy};
		}
		double a = dist(ps[2], ps[0]);
		double b = dist(ps[0], ps[1]);
		double c = dist(ps[1], ps[2]);
		double cs = (a + b - c) / (2 * sqrt(a) * sqrt(b));
		double sn = sqrt(1 - pow2(cs));
		double r = sqrt(c / (2 - 2 * (pow2(cs) - pow2(sn))));
		cout << 2 * PI * r << '\n';
	}
	return 0;
}