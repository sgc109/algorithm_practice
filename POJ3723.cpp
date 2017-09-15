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

typedef pair<int,pair<int,int> > edge;
vector<edge> edges;
int T, N, M, R;
int par[20003];
int find(int a){
	return par[a] == a ? a : par[a] = find(par[a]);
}
void merge(int a, int b){
	a = find(a), b = find(b);
	par[a] = b;
}
int BOY(int x){
	return N + x;
}
int GIRL(int x){
	return x;
}
int main() {
	scanf("%d", &T);
	while(T--){
		edges.clear();
		for(int i = 0 ; i < 20003; i++) par[i] = i;
		scanf("%d %d %d", &N, &M, &R);
		while(R--){
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d);
			edges.push_back(make_pair(-d, make_pair(BOY(x), GIRL(y))));
		}
		int sum = 0;
		sort(all(edges));
		for(int i = 0 ; i < sz(edges); i++){
			edge e = edges[i];
			int a = e.second.first, b = e.second.second;
			if(find(a) == find(b)) continue;
			int d = -e.first;
			sum += d;
			merge(a, b);
		}
		printf("%d\n", (N + M) * 10000 - sum);
	}
	return 0;
}