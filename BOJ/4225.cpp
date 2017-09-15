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
const double EPS = 1e-9;
struct point{
	double x, y;
	point operator-(const point& rhs) const{
		return point{x - rhs.x, y - rhs.y};
	}
	point operator+(const point& rhs) const{
		return point{x + rhs.x, y + rhs.y};
	}
	double cross(const point& rhs){
		return x * rhs.y - y * rhs.x;
	}
	double dot(const point& rhs){
		return x * rhs.x + y * rhs.y;
	}
	bool operator<(const point& rhs) const{
		if(x != rhs.x) return x < rhs.x;
		return y < rhs.y;
	}
	point operator*(int k){
		return point{x * k, y * k};
	}
} ps[103];
int N;
double ccw(point& a, point& b, point& c){
	return (a - c).cross(b - c);
}
double dist(point& a, point& b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double dist(point l1, point l2, point p){
	point tl1 = (l1 - l2) * 10000 + l1;
	point tl2 = (l2 - l1) * 10000 + l2;
	l1 = tl1, l2 = tl2;
	point lo = l1, hi = l2;
	for(int i = 0 ; i < 300; i++){
		point mid = point{(lo.x + hi.x) / 2, (lo.y + hi.y) / 2};
		double dt = (mid - p).dot(l1 - mid);
		if(dt >= -EPS) lo = mid;
		else hi = mid;
	}
	return dist(lo, p);
}
vector<point> convex;
void print(){
	for(auto p : convex){
		printf("(%lf, %lf)\n", p.x, p.y);
	}
	printf("----------------------------------\n");
}
int main() {
	// freopen("output.txt", "w", stdout);
	fastio();
	cout.precision(2);
	cout << fixed;
	for(int t = 1; ; t++){
		// convex.clear();
		cin >> N;
		if(!N) break;
		for(int i = 0 ; i < N; i++){
			int xx, yy;
			cin >> xx >> yy;
			ps[i] = point{(double)xx, (double)yy};
		}
		double aans = 0;
		for(int k = 0 ; k < 2; k++){
			convex.clear();
			for(int i = 0 ; i < N; i++){
				while(sz(convex) >= 2 && ccw(convex.back(), ps[i], convex[sz(convex) - 2]) <= EPS) convex.pop_back();
				convex.pb(ps[i]);
				// print();
			}
			
			convex.pb(ps[0]);
			double ans = infl;
			for(int i = 0 ; i < sz(convex) - 1; i++){
				auto p1 = convex[i];
				auto p2 = convex[i + 1];
				double maxx = -1;
				for(int j = 0 ; j < sz(convex) - 1; j++){
					if(j == i || j == i + 1) continue;
					double d = dist(p1, p2, convex[j]);
					maxx = max(maxx, d);
				}
				ans = min(ans, maxx);
			}
			
			aans = max(aans, ans);
			reverse(ps + 1, ps + N);
		}
		cout << "Case " << t << ": ";
		cout << ceilf(aans * 100) / 100.0 << '\n';
	}
	return 0;
}
