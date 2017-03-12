#include <bits/stdc++.h>
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
const int INF = 0x2a2a2a2a;
const long long INFL = 0x2a2a2a2a2a2a2a2a;
const int MAX_N = 102;

long long minCostAdd[33];
long long minCostErase[33];
long long costAdd[33];
long long costErase[33];
long long dist[33][33];
long long dp[53][53];

class PalindromizationDiv1{
public:
	int N;
	string S;
	void read(vector<string>& operations){
		for(auto s : operations){
			if(s[0]=='e'){
				string op = "erase ";
				int pos = op.size();
				int c = s[pos]-'a';
				int cost = strtol(s.substr(pos+2,s.size()-(pos+2)).c_str(),0,10);
				costErase[c] = cost;
			}
			else if(s[0]=='a'){
				string op = "add ";
				int pos = op.size();
				int c = s[pos]-'a';
				int cost = strtol(s.substr(pos+2,s.size()-(pos+2)).c_str(),0,10);
				costAdd[c] = cost;
			}
			else if(s[0]=='c'){
				string op = "change ";
				int pos = op.size();
				int c1,c2;
				c1 = s[pos]-'a';
				pos+=2;
				c2 = s[pos]-'a';
				int cost = strtol(s.substr(pos+2,s.size()-(pos+2)).c_str(),0,10);	
				dist[c1][c2] = cost;
			}
		}
	}

	void floyd(){FOR(k,26) FOR(i,26) FOR(j,26) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);}

	long long go(int s, int e){
		if(s>=e) return 0;
		long long& cache = dp[s][e];
		if(cache != -1) return cache;
		long long ret = INFL;
		FOR(i,26) ret = min(ret, go(s+1, e-1) + dist[S[s]-'a'][i] + dist[S[e]-'a'][i]);
		FOR(i,26) ret = min(ret, go(s+1, e) + dist[S[s]-'a'][i] + minCostAdd[i]);
		FOR(i,26) ret = min(ret, go(s, e-1) + dist[S[e]-'a'][i] + minCostAdd[i]);
		ret = min(ret, go(s+1, e-1) + minCostErase[S[s]-'a'] + minCostErase[S[e]-'a']);
		ret = min(ret, go(s+1, e) + minCostErase[S[s]-'a']);
		ret = min(ret, go(s, e-1) + minCostErase[S[e]-'a']);
		return cache = ret;
	}

	int getMinimumCost(string word, vector <string> operations){
		memset(dp,-1,sizeof(dp));
		memset(dist,0x2a,sizeof(dist));
		memset(costAdd,0x2a,sizeof(costAdd));
		memset(costErase,0x2a,sizeof(costErase));
		memset(minCostAdd,0x2a,sizeof(minCostAdd));
		memset(minCostErase,0x2a,sizeof(minCostErase));
		FOR(i,26) dist[i][i] = 0;
		N = word.size();
		S = word;
		read(operations);
		floyd();
		FOR(i,26){
			FOR(j,26){
				if(costErase[j]==INFL) continue;
				minCostErase[i] = min(minCostErase[i], dist[i][j] + costErase[j]);
			}
		}
		FOR(i,26){
			if(costAdd[i]==INFL) continue;
			FOR(j,26){
				minCostAdd[j] = min(minCostAdd[j], dist[i][j] + costAdd[i]);
			}
		}
		long long ret = go(0,N-1);
		if(ret >= INFL) ret = -1;
		return (int)ret;
	}
};