#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
const double PI = acos(-1);
const double EPS = 1e-9;
struct point{
	int x,y;
};
int n;
point points[4003];
int ruined[4003];
double gak1, gak2;
double dist(point A, point B){
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
double isZero(double x){
	return fabs(x) <= EPS;
}
int main() {
	cout.precision(10);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int x,y;
		cin >> x >> y;
		points[i] = point{x,y};
	}
	cin >> gak1 >> gak2;
	gak2 += gak1;
	gak1 = gak1/180*PI;
	gak2 = gak2/180*PI;
	for(int i = 0 ; i < n; i++){
		double gak;
		if(points[i].x == 0 && points[i].y == 0){
			ruined[i] = 1;
			continue;
		}
		if(points[i].y == 0) {
			if(points[i].x < 0) gak = PI;
			else gak = 0;
		}
		else {
			gak = atan2((double)points[i].y, (double)points[i].x);
			if(gak <= EPS) gak += 2*PI;
		}
		if(gak1 <= gak + EPS && gak <= gak2 + EPS) ruined[i] = 1;
	}
	double ans = 0;
	for(int i = 0 ; i < n ; i++){
		if(ruined[i]) continue;
		for(int j = i+1; j < n; j++){
			if(ruined[j]) continue;
			ans = max(ans, dist(points[i], points[j]));
		}
	}
	cout << ans;
	return 0;
}