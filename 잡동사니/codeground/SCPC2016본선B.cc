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
const int MAX_N = 5002;

int dp[MAX_N];
vi pi[MAX_N];
int n;
vi getPartial(string S){
	vi ret(S.size(),0);
	int size = S.size();
	int begin = 1;
	int matched = 0;
	while(begin+matched < size){
		if(S[begin+matched]==S[matched] && matched+1 <= (begin+matched+1)>>1){
			matched++;
			ret[begin+matched-1] = matched;
		}
		else {
			if(matched==0) begin++;
			else {
				begin += matched-ret[matched-1];
				matched = ret[matched-1];
			}
		}
	}
	return ret;
}
int solve(int pos){
	if(pos>=n) return 0;
	int& cache = dp[pos];
	if(cache != -1) return cache;
	int ret=INF;
	for(int i = 1; pos+i<n; i++){
		if(pi[pos][i]>0) ret=min(ret,1+solve(pos+i+1));
	}
	return cache = ret;
}
int main() {
	int T;
	inp1(T);
	FOR(t,T){
		memset(dp,-1,sizeof(dp));
		FOR(i,MAX_N) pi[i].clear();
		inp1(n);
		string S;
		cin >> S;
		FOR(i,n){
			string Ss = S.substr(i);
			pi[i] = getPartial(Ss);
		}
		int ans = solve(0);
		if(ans==INF) ans=0;
		printf("Case #%d\n%d\n",t+1,ans);
	}
	return 0;
}