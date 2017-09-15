#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>	
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int victim[50003];
int par[50003];
int find(int u){
	return par[u] == u ? u : par[u] = find(par[u]);
}
int merge(int a, int b){
	if(!a || !b) return a + b;
	a = find(a), b = find(b);
	if(a == b) return a;
	if(victim[a] == b || victim[b] == a || victim[victim[a]] == b || victim[victim[b]] == a) return -1;
	int ret = merge(victim[a], victim[b]);
	if(ret == -1) return -1;
	par[b] = a;
	victim[a] = ret;
	return a;
}
int N, K;
int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0 ; i <= N; i++) par[i] = i;
	int ans = 0;
	for(int i = 1; i <= K; i++){
		int a, x, y;
		scanf("%d %d %d", &a, &x, &y);
		if(x < 1 || N < x || y < 1 || N < y) ans++;
		else if(a == 1){
			if(merge(x, y) == -1) ans++;
		}
		else if(a == 2){
			if(find(x) == find(y)) ans++;
			else if(merge(victim[x], y) == -1) ans++;
			else if(merge(victim[victim[victim[x]]], x) == -1) ans++;
			else victim[find(x)] = find(y);		
		}
	}
	cout << ans;
	return 0;
}