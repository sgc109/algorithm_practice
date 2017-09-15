#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int base = 257;
ll poww[4000003];
ll verSum[2003][2003], horSum[2003][2003];
ll R[2003][2003];
int H2,W2,H1,W1;
char str2[2003][2003], str1[2003][2003];
int main() {
	poww[0] = 1;
	for(int i = 0 ; i < 4000000; i++) poww[i+1] = poww[i] * base;

	scanf("%d %d %d %d", &H2, &W2, &H1, &W1);
	for(int i = 0 ; i < H2; i++) scanf("%s", str2[i]);
	for(int i = 0 ; i < H1; i++) scanf("%s", str1[i]);

	for(int i = 0 ; i < H1; i++){
		for(int j = 0 ; j < W2; j++) horSum[i][W2-1] = horSum[i][W2-1] * base + str1[i][j];
		for(int j = W2; j < W1; j++) horSum[i][j] = (horSum[i][j-1] - str1[i][j - W2] * poww[W2-1]) * base + str1[i][j];
	}
	for(int j = 0 ; j < W1; j++){
		for(int i = 0 ; i < H2; i++) verSum[H2-1][j] = verSum[H2-1][j] * poww[W1] + str1[i][j];
		for(int i = H2; i < H1; i++) verSum[i][j] = (verSum[i-1][j] - str1[i - H2][j] * poww[W1 * (H2-1)]) * poww[W1] + str1[i][j];
	}

	ll& h1 = R[H2-1][W2-1];
	ll h = 0;
	h1 = 0;
	for(int i = 0 ; i < H2; i++){
		for(int j = 0 ; j < W2; j++){
			h = h * base + str2[i][j];
			h1 = h1 * base + str1[i][j];
		}
		if(i == H2 - 1) break;
		h *= poww[W1 - W2];
		h1 *= poww[W1 - W2];
	}

	int ans = 0;
	
	for(int i = H2 - 1; i < H1; i++){
		for(int j = W2 - 1; j < W1; j++){
			if(R[i][j] == h) ans++;
			if(j < W1 - 1) R[i][j+1] = (R[i][j] - verSum[i][j-W2+1] * poww[W2-1]) * base + verSum[i][j+1];
			if(i < H1 - 1 && j == W1 - 1) R[i+1][W2-1] = (R[i][W2-1] - horSum[i-H2+1][W2-1] * poww[W1 * (H2-1)]) * poww[W1] + horSum[i+1][W2-1];
		}
	}

	printf("%d\n",ans);
	return 0;
}	