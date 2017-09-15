#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int base = 2003;
int h,w,H,W;
char pic[2003][2003], PIC[2003][2003];
int hashed[2003][2003];
map<ll, int> num;
int cnt;
ll poww2, powwb;
int main() {
	scanf("%d %d %d %d\n", &h, &w, &H, &W);
	for(int i = 0 ; i < h; i++) gets(pic[i]);
	for(int i = 0 ; i < H; i++) gets(PIC[i]);

	poww2 = powwb = 1;
	for(int i = 0; i < w; i++) poww2 = poww2 * 3;
	for(int i = 0; i < h; i++) powwb = powwb * base;

	ll r = 0;
	for(int i = 0 ; i < h; i++){
		ll h = 0;
		for(int j = 0 ; j < w; j++){
			h = h * 3 + (pic[i][j] == 'o');
		}
		if(num.find(h) == num.end()) num[h] = ++cnt;
		r = r * base + num[h];
	}

	for(int i = 0 ; i < H; i++){
		ll H = 0;
		for(int j = 0 ; j < w; j++) {
			H = H * 3 + (PIC[i][j] == 'o');
		}
		for(int j = w ; j <= W; j++) {n
			if(num.find(H) != num.end()) hashed[i][j-w] = num[H];
			if(j == W) break;
			H *= 3;
			H += (PIC[i][j] == 'o');
			H -= poww2 * (PIC[i][j-w] == 'o');
		}
	}

	int ans = 0;
	for(int j = 0 ; j <= W-w; j++){
		ll R = 0;
		for(int i = 0 ; i < h; i++){
			R = R * base + hashed[i][j];
		}
		for(int i = h ; i <= H; i++){
			if(R == r) ans++;
			if(i == H) break;
			R *= base;
			R += hashed[i][j];
			R -= powwb * hashed[i-h][j];
		}
	}

	cout << ans;
	return 0;
}