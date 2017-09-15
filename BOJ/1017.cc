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

vi G[53];
int notPrime[2003],N,A[53],matched[53],visited[53];
bool dfs(int here){
	if(visited[here]) return false;
	visited[here]=1;
	for(int there : G[here]){
		if(there==0 || there==matched[0]) continue;
		if(matched[there]==-1 || dfs(matched[there])){
			matched[there]=here;
			matched[here]=there;
			return true;
		}
	}
	return false;
}
int main() {
	notPrime[1]=1;
	for(int i=2;i*i<=2000;i++){
		if(notPrime[i]) continue;
		for(int j=2*i;j<=2000;j+=i) notPrime[j]=1;
	}
	inp1(N);
	FOR(i,N) inp1(A[i]);
	FOR(i,N){
		REP(j,i+1,N-1){
			if(!notPrime[A[i]+A[j]]) {
				G[i].pb(j);
				G[j].pb(i);
			}
		}
	}
	vi ans;
	REP(i,1,N-1){
		if(notPrime[A[0]+A[i]]) continue;
		memset(matched,-1,sizeof(matched));
		matched[0]=i;
		matched[i]=0;
		int cnt=0;
		FOR(j,N) {
			memset(visited,0,sizeof(visited));
			if(matched[j]!=-1||dfs(j)) {
				cnt++;
			}
		}
		if(cnt==N) ans.pb(A[i]);
	}
	if(sz(ans)==0){
		printf("-1");
		return 0;
	}
	sort(all(ans));
	FOR(i,sz(ans)) printf("%d ",ans[i]);
	return 0;
}
