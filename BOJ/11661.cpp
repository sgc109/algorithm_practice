#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

ll A, B, C, X1, X2, Y1, Y2, gcd;
ll trash;
ll xGCD(ll a, ll b, ll& x, ll& y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	ll x1, y1;
	ll ret = xGCD(b, a % b, x1, y1);
	x = y1, y = x1 - (a / b) * y1;
	return ret;
}

// ll floordiv(ll a, ll b);
// ll ceildiv(ll a, ll b);

// ll floordiv(ll a, ll b) {
// 	if (b < 0) return floordiv(-a, -b);
// 	if (a < 0) return -ceildiv(-a, b);
// 	return a / b;
// }
// ll ceildiv(ll a, ll b) {
// 	if (b < 0) return ceildiv(-a, -b);
// 	if (a < 0) return -floordiv(-a, b);
// 	return (a + b - 1) / b;
// }

// ll findRng(ll x0, ll y0, ll a, ll b) {
// 	ll g = xGCD(a, b, trash, trash);
// 	ll dx = b / g, dy = -a / g;
// 	ll tx1, tx2, ty1, ty2;
// 	if (dx > 0) {
// 		tx1 = ceildiv(X1 - x0, dx);
// 		tx2 = floordiv(X2 - x0, dx);
// 	}
// 	else {
// 		tx1 = ceildiv(X2 - x0, dx);
// 		tx2 = floordiv(X1 - x0, dx);
// 	}
// 	if (dy > 0) {
// 		ty1 = ceildiv(Y1 - y0, dy);
// 		ty2 = floordiv(Y2 - y0, dy);
// 	}
// 	else {
// 		ty1 = ceildiv(Y2 - y0, dy);
// 		ty2 = floordiv(Y1 - y0, dy);
// 	}
// 	return max(0ll, min(tx2, ty2) - max(tx1, ty1) + 1);
// }

ll findRng(ll x0, ll y0, ll a, ll b){
	ll g = xGCD(a, b, trash, trash);
	ll dx = b / g, dy = -a / g;
	ll tx1, tx2, ty1, ty2;
	if(x0 <= X1) tx1 = (X1 - x0 + abs(dx) - 1) / dx;
	else tx1 = (X1 - x0) / dx;
	if(X2 < x0 + tx1 * dx) return 0;

	if(x0 <= X2) tx2 = (X2 - x0) / dx;
	else tx2 = (X2 - x0 - abs(dx) + 1) / dx;
	if(x0 + tx2 * dx < X1) return 0;

	if(y0 <= Y1) ty1 = (Y1 - y0 + abs(dy) - 1) / dy;
	else ty1 = (Y1 - y0) / dy;
	if(Y2 < y0 + ty1 * dy) return 0;

	if(y0 <= Y2) ty2 = (Y2 - y0) / dy;
	else ty2 = (Y2 - y0 - abs(dy) + 1) / dy;
	if(y0 + ty2 * dy < Y1) return 0;

	if(tx1 > tx2) swap(tx1, tx2);
	if(ty1 > ty2) swap(ty1, ty2);

	// cout << "tx1 : " << tx1 << ", tx2 : " << tx2 << ", ty1 : " << ty1 << ", ty2 : " << ty2 << endl;
	return max(0ll, min(tx2, ty2) - max(tx1, ty1) + 1);
}
int main() {
	cin >> A >> B >> C >> X1 >> X2 >> Y1 >> Y2;
	if(X1 > X2 || Y1 > Y2) return !printf("0");
	if(!A && !B && !C) return !printf("%lld", (X2 - X1 + 1) * (Y2 - Y1 + 1));
	if(!A && !B) return !printf("0");
	if(!A && B && !C) {
		if(Y1 <= 0 && 0 <= Y2) return !printf("%lld", X2 - X1 + 1);
		return !printf("0");
	}
	if(A && !B && !C) {
		if(X1 <= 0 && 0 <= X2) return !printf("%lld", Y2 - Y1 + 1);
		return !printf("0");
	}
	if(!A && B && C) {
		if(abs(C) % abs(B)) return !printf("0");
		if(Y1 <= -C / B && -C / B <= Y2) return !printf("%lld", X2 - X1 + 1);
		return !printf("0");
	}
	if(A && !B && C) {
		if(abs(C) % abs(A)) return !printf("0");
		if(X1 <= -C / A && -C / A <= X2) return !printf("%lld", Y2 - Y1 + 1);
		return !printf("0");
	}
	ll startX, startY;
	ll trash;
	ll gcd2 = xGCD(abs(A), abs(B), trash, trash);
	ll gcd3 = xGCD(gcd2, abs(C), trash, trash);
	A /= gcd3, B /= gcd3, C /= gcd3;
	gcd = xGCD(abs(A), abs(B), trash, trash);
	if(C % gcd) return !printf("0");

	if(!C) startX = 0, startY = 0;
	else {
		int minusA = A < 0;
		int minusB = B < 0;
		ll x, y;
		xGCD(abs(A), abs(B), x, y);
		x = x * (minusA ? -1 : 1);
		y = y * (minusB ? -1 : 1);
		startX = x * (-C);
		startY = y * (-C);
	}

	ll ans = findRng(startX, startY, A, B);

	cout << ans;
	return 0;
}