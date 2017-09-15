// #include <bits/stdc++.h>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
int N, ML, MD;
vector<pair<int,int> > G[1003];
int d[1003];
bool bellman(int S){
	d[0] = 0;
	bool ret = false;
	for(int k = 0 ; k < N; k++){
		for(int i = 0; i < N; i++){
			for(auto p : G[i]){
				int j = p.first;
				int c = p.second;
				if(d[i] + c < d[j]){
					d[j] = d[i] + c;
					if(k == N - 1) ret = true;
				}
			}
		}
	}	
	return ret;
}
int main() {
	memset(d,0x3c,sizeof(d));
	scanf("%d %d %d", &N, &ML, &MD);
	for(int i = 0 ; i < N - 1; i++) G[i + 1].push_back({i, 0});
	while(ML--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		G[a].push_back({b, c});
	}
	while(MD--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		G[b].push_back({a, -c});
	}

	if(bellman(0)) return !printf("-1");
	if(d[N - 1] == inf) return !printf("-2");
	printf("%d", d[N - 1]);

	return 0;
}