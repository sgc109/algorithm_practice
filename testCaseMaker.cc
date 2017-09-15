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

struct RNG{
	int a, b;
	int seed;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed*(long long)a)+b)%20090711;
		return ret;
	}
};

int T,N,M,K,R,P;
int main() {
	freopen("input.txt","w",stdout);
	RNG rng(243251, 109);
	cout << 10000 << ' ' << 9999 << '\n';
	cout << "-1 1 2\n";
	for(int i = 0 ; i < 9998; i++) cout << 1 << ' ' << 2 << ' ' << i + 3 << endl;
	return 0;
}