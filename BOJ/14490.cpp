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

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
int main() {
	fastio();
	int a, b;
	scanf("%d:%d\n", &a, &b);
	int g = gcd(a, b);
	printf("%d:%d\n", a / g, b / g);
	return 0;
}