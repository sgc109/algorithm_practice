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

struct point{
	int x, y;
};
int x, y;
point ps[5];
int ok[5];
int main() {
	fastio();							
	cin >> x >> y;
	int same = (x % 1 == y % 1);
	for(int i = 0 ; i < 5; i++) cin >> ps[i].x >> ps[i].y;
	for(int i = 0 ; i < 5; i++) ok[i] = 1;
	for(int i = 0 ; i < 5; i++){
		if(ps[i].x < ps[i].y != x < y) ok[i] = 0;
		else if(ps[i].x > ps[i].y != x > y) ok[i] = 0;
		else {
			if(same) continue;
			if(ps[i].x - ps[i].y != x - y) ok[i] = 0;
		}
	}
	for(int i = 0 ; i < 5; i++) cout << (ok[i] ? 'Y' : 'N') << '\n';
	return 0;
}