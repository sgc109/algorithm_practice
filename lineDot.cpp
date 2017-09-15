#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct vector2{
	double x,y,z;
	vector2(double xx, double yy, double zz):x(xx), y(yy), z(zz){}
	vector2 operator*(double k) {
		return vector2(k*x, k*y, k*z);
	}
	double dot(vector2 rhs){
		return x*rhs.x + y*rhs.y + z*rhs.z;
	}
	vector2 operator-(const vector2& rhs) const{
		return vector2(x-rhs.x, y-rhs.y, z-rhs.z);
	}
	vector2 operator+(const vector2& rhs) const{
		return vector2(x+rhs.x, y+rhs.y, z+rhs.z);
	}
};

double poww(double x){return x*x;}
double dist(vector2 A, vector2 B){
	return sqrt((A-B).dot(A-B));
}
int main() {
	int ax, ay, az;
	cin >> ax >> ay >> az;
	int bx, by, bz;
	cin >> bx >> by >> bz;
	int cx, cy, cz;
	cin >> cx >> cy >> cz;
	vector2 A(ax, ay, az);
	vector2 B(bx, by, bz);
	vector2 C(cx, cy, cz);
	double D = sqrt((A-B).dot(A-B));
	double l = 0, r = D;
	for(int i = 0 ; i < 10000; i++){
		double m1 = (2*l + r) / 3;
		double m2 = (l + 2*r) / 3;
		double d1 = dist(A+(B-A)*(m1/D), C);
		double d2 = dist(A+(B-A)*(m2/D), C);
		if(d1 < d2) r = m2;
		else l = m1;
	}
	printf("%.10lf\n",dist(A+(B-A)*(l/D), C));
	return 0;
}