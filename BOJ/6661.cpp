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
int N, M;
double X[40003], Y[40003];
int h[10003];
double angle[40003];
double pre[10003];
void update(int pos, double val, int nl, int nr, int nd){
	int nm = (nl + nr) / 2;
	if(pos < nl || nr < pos) return;
	if(nl == nr) return;
	update(pos, val, nl, nm, 2 * nd);
	update(pos, val, nm + 1, nr, 2 * nd + 1);
	if(pos <= nm) angle[nd] += val;
	X[nd] = X[2 * nd] + cos(angle[nd]) * X[2 * nd + 1] - sin(angle[nd]) * Y[2 * nd + 1];
	Y[nd] = Y[2 * nd] + sin(angle[nd]) * X[2 * nd + 1] + cos(angle[nd]) * Y[2 * nd + 1];
}
void init(int nl, int nr, int nd){
	if(nl == nr){
		Y[nd] = h[nl];
		return;
	}
	int nm = (nl + nr) / 2;
	init(nl, nm, 2 * nd);
	init(nm + 1, nr, 2 * nd + 1);
	Y[nd] = Y[2 * nd] + Y[2 * nd + 1];
}
int main() {
	fastio();
	cout.precision(2);
	cout << fixed;
	while(cin >> N >> M){
		for(int i = 0 ; i < 30003; i++) angle[i] = X[i] = Y[i] = 0.0;
		for(int i = 0 ; i < N; i++) pre[i] = PI;
		for(int i = 0 ; i < N; i++) cin >> h[i];
		init(0, N - 1, 1);
		for(int i = 0 ; i < M; i++) {
			int id, deg;
			cin >> id >> deg;
			id--;
			double d = deg * PI / 180;
			update(id, d - pre[id], 0, N - 1, 1);
			pre[id] = d;
			cout << X[1] << ' ' << Y[1] << '\n';
		}
		cout << '\n';
	}	
	return 0;
}