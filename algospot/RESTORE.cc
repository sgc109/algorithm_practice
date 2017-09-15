#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 15;

string str[MAX_N];
int check[MAX_N];
int K;
int n;
int adj[MAX_N][MAX_N];

int LCP(string& A, string& B){
	int ret=0;
	FOR(i,min(A.size(),B.size())){
		int common=0;
		FOR(j,i+1){
			if(A[A.size()-1-i+j] == B[j]) common++;
			else break;
		}
		if(common==i+1) ret=i+1;
	}
	return ret;
}
int dp[1<<MAX_N][MAX_N];
int solve(int visited, int here){
	int& cache = dp[visited][here];
	if(cache!=-1) return cache;

	if(visited==(1<<n)-1) return cache=0;
	int ret=0;
	FOR(i,n){
		if((visited>>i)&1) continue;
		ret = max(ret,(visited?adj[here][i]:0)+solve(visited|(1<<i),i));
	}
	return cache = ret;
}

void trace(int visited, int here, vi& order){
	if(order.size()==n) return;

	FOR(i,n){
		if((visited>>i)&1) continue;
		if(dp[visited|(1<<i)][i]==dp[visited][here]-(visited?adj[here][i]:0)){
			order.pb(i);
			trace(visited|(1<<i),i,order);
			return;
		}
	}
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(adj,0,sizeof(adj));
		memset(check,0,sizeof(check));
		memset(dp,-1,sizeof(dp));
		inp1(K);
		FOR(i,K) cin >> str[i];
		FOR(i,K){
			FOR(j,K){
				if(i==j) continue;
				if(str[i].find(str[j])!=string::npos && !check[i]) check[j]=1;
			}
		}
		vector<string> v;
		FOR(i,K) if(!check[i]) v.pb(str[i]);
		n=v.size();
		FOR(i,n){
			FOR(j,n){
				if(i==j) continue;
				adj[i][j]=LCP(str[i],str[j]);
			}
		}
		solve(0,0);
		vi order;
		trace(0,0,order);
		string ans;
		FOR(i,order.size()-1){
			ans+=v[order[i]].substr(0,v[order[i]].size()-adj[order[i]][order[i+1]]);
		}
		ans+=v[order[order.size()-1]];
		cout << ans << endl;

	}	
	return 0;
}