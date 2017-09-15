// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
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
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,k,a,b;
int aMatch[10003],bMatch[10003],level[10003];
vi G[10003];
bool dfs(int here){
	for(int there : G[here]){
		if(bMatch[there]==-1 || level[bMatch[there]] == level[here]+1 && dfs(bMatch[there])){
			aMatch[here] = there;
			bMatch[there] = here;
			return true;
		}
	}
	return false;
}
int hopcroft(){
	int ret=0;
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	while(1){
		memset(level,-1,sizeof(level));
		queue<int> q;
		FOR(i,N) if(aMatch[i]==-1) q.push(i),level[i]=0;
		if(q.empty()) break;
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(int there : G[here]){
				if(bMatch[there]==-1||level[bMatch[there]]!=-1) continue;
				level[bMatch[there]] = level[here] + 1;
				q.push(bMatch[there]);
			}
		}
		int add=0;
		FOR(i,N) {
			if(aMatch[i]!=-1) continue;
			if(dfs(i)) add++;
		}
		if(!add) break;
		ret+=add;
	}
	return ret;
}
int main() {
	while(scanf("%d",&N)!=-1){
		FOR(i,10003) G[i].clear();
		FOR(i,N){
			scanf("%d: (%d)",&a,&k);
			FOR(j,k){
				scanf("%d",&b);
				G[a].pb(b-N);
			}
		}
		int ans = hopcroft();
		printf("%d\n",ans);
	}
	return 0;
}
