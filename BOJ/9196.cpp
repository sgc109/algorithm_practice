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

int H, W;
bool cmp(int h1, int w1, int h2, int w2){
	if(h1 * h1 + w1 * w1 < h2 * h2 + w2 * w2) return true;
	if(h1 * h1 + w1 * w1 == h2 * h2 + w2 * w2 && h1 < h2) return true;
	return false;
}
int main() {
	fastio();
	while(1){
		cin >> H >> W;
		if(!H && !W) break;
		int ansh = 10000, answ = 10000;
		for(int w = 2; w <= 150; w++){
			for(int h = 1; h < w; h++){
				if(cmp(H, W, h, w) && cmp(h, w, ansh, answ)){
					ansh = h, answ = w;
				}
			}
		}
		cout << ansh << ' ' << answ << '\n';
	}
	return 0;
}