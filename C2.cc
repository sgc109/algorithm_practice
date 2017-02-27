// #include <bits/stdc++.h>
// #include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000002;

int N,a,b,c,root;
vi G[MAX_N];
int w[MAX_N];
vi third[MAX_N];
void dfs(int here){
	for(int there : G[here]){
		dfs(there);
		w[here]+=w[there];
	}
}
int dfs2(int here){
	for(int there : G[here]){
		int ret = dfs2(there);
		if(ret) third[here].pb(ret);
	}
	if(sz(third[here])>=2){
		printf("%d %d",third[here][0],third[here][1]);
		exit(0);
	}
	return (here!=root && w[root]==w[here]*3)?here:(sz(third[here])?third[here][0]:0);
}

void dfs3(int here){
	if(here!=root && w[here]==w[root]*2/3 && sz(third[here])){
		printf("%d %d",here,third[here][0]);
		exit(0);
	}
	for(int there : G[here]){
		dfs3(there);
	}
}
int main() {
	inp1(N);	
	REP(i,1,N){
		inp2(a,b);
		if(a) G[a].pb(i);
		else root=i;
		w[i]=b;
	}
	dfs(root);
	if(w[root]%3){
		printf("-1");
		return 0;
	}
	dfs2(root);
	dfs3(root);
	printf("-1");
	return 0;
}
