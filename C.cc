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
const int MAX_N = 1000003;

vi G[MAX_N];
int t[MAX_N];
int N,a,b;
ll w[MAX_N];
int ans1, ans2,root,rootbak;
void dfs(int here){
	for(int there : G[here]){
		if(there==ans1) continue;
		dfs(there);
		w[here]+=w[there];
	}
}
int dfs2(int here, int type){
	if(type){
		if(here!=root&&((w[root]-w[here])*2==w[here])){
			ans1=here;
			return 1;`
		}
	}
	else {
		if(here!=root&&(w[root]-w[here]==2*w[here])){
			ans1=here;
			return 1;
		}
	}
	for(int there : G[here]){
		int ret = dfs2(there,type);
		if(ret) return ret;
	}
	return 0;
}
int dfs3(int here){
	if(here!=root&&(w[root]-w[here]==w[here])) {
		ans2=here;
		return 1;
	}
	for(int there : G[here]){
		if(there==ans1) continue;
		if(dfs3(there)) return 1;
	}
	return 0;
}
void init(){
	REP(i,1,N) w[i]=t[i];
}

int solve1(){
	root=rootbak;
	ans1=0,ans2=0;
	init();
	dfs(root);
	int ret = dfs2(root,1);
	if(!ret) return 0;
	root=ans1;
	init();
	dfs(root);
	return dfs3(root);
}
int solve2(){
	root=rootbak;
	ans1=0,ans2=0;
	init();
	dfs(root);
	int ret = dfs2(root,0);
	if(!ret) return 0;
	init();
	dfs(root);
	return dfs3(root);
}
int main() {
	inp1(N);
	REP(i,1,N){
		inp2(a,b);
		if(a) G[a].pb(i);
		else rootbak=i;
		t[i]=b;
	}
	if(solve1()||solve2()) printf("%d %d",ans1,ans2);
	else printf("-1");

	return 0;
}
