#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int par[150003];
int N, K;
int find(int a){
	return par[a] == a ? a : par[a] = find(par[a]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	par[a] = b;
}
bool same(int a, int b){
	return find(a) == find(b);
}
bool inRange(int x){
	return 0 <= x && x < N;
}
int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0 ; i < 3 * N; i++) par[i] = i;
	int ans = 0;
	while(K--){
		int a,x,y;
		scanf("%d %d %d", &a, &x, &y);
		x--, y--;
		if(!inRange(x) || !inRange(y)) {
			ans++;
			continue;
		}
		if(a == 1){
			int ok = 1;
			for(int i = 0 ; i < 3; i++){
				for(int j = 0 ; j < 3; j++){
					if(i == j) continue;
					if(same(x + i * N, y + j * N)) ok = 0;
				}
			}
			if(!ok) {
				ans++;
				continue;
			}
			for(int i = 0 ; i < 3; i++) merge(x + i * N, y + i * N);
		}
		else if(a == 2){
			int ok = 1;
			for(int i = 0 ; i < 3; i++){
				for(int j = 0 ; j < 3; j++){
					if((i + 1) % 3 == j) continue;
					if(same(x + i * N, y + j * N)) ok = 0;
				}
			}
			if(!ok) {
				ans++;
				continue;
			}
			for(int i = 0 ; i < 3; i++){
				merge(x + i * N, y + ((i + 1) % 3) * N);
			}
		}
	}

	printf("%d", ans);
	return 0;
}