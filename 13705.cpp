#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;
const long double EPS = 1e-9;
ll A, B, C;
int main() {
	fastio();
    cin >> A >> B >> C;
    long double l = 0.0, r = 100002.0;
    for(int i = 0; i < 10000; i++){
        long double mid = (l + r) / 2;
        long double res = A * mid + B * sin(mid);
        if(res < C) l = mid;
        else r = mid;
    }
    cout.precision(6);
    cout << fixed;
    cout << l;
	return 0;
}
