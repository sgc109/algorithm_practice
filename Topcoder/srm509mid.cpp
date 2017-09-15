/*
https://community.topcoder.com/stat?c=problem_statement&pm=11443

주어진 문자열을 팰린드롬으로 만드는 dp 문제이다.
부분문제를 정의하자면
dp(i,j) : S[i:j] 를 팰린드롬으로 만들기위한 최소 비용

점화식을 생각해보면 양 끝에서 부터 한글자 혹은 두글자씩 매치시키면서 양쪽 끝을 한칸 씩 좁혀나가는 식으로 구성할 수가 있다.
어떻게 이게 가능하냐면 왼쪽끝 글자를 l, 오른쪽끝 글자를 r 이라고 했을때 l은 r과 매치시킬 수도있고 오른쪽에 새 글자를 만들어서 그것과 
매치시킬 수도있고 r을 삭제하고 r의 왼쪽 글자에대해 재귀적으로 선택할수가있다. 그렇기 때문에
dp(i,j) = min(
				dp(i+1,j-1)+l과r을 같게만드는 최소비용,
				dp(i+1,j)+새글자를만들어서 l과 같게만드는 최소비용,
				dp(i,j-1)+새글자를만들어서 r과 같게만드는 최소비용)
		)

구현을 간단하게 하려면 투명 문자라는 것을 하나 도입하여 지우는 것은 문자를 투명문자로 바꾸는 것으로, 만드는 것은 투명문자를 
만드려는 문자로 바꾸는 것으로 생각하면 간편하다. 두 문자를 삭제하는거라면 두 문자를 투명한 문자로 같게 만든다고 생각하면된다.
그러면 플로이드로 최단거리를 구할 때 어떤 문자를 지우는데 드는 비용을 그 문자에서 투명 문자로 가는 비용으로 보면 되고
어떤 문자를 만드는데 드는 비용은 투명 문자에서 만들려는 문자로 가는 비용으로 보고 플로이드를 돌리면된다.

*/

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
	void read(vector<string> operations){
		for(auto s : operations){
			istringstream is(s);
			string op;
			int cost;
			char c,c1,c2;
			is >> op;
			if(op=="erase"){
				is >> c >> cost;
				dist[c-'a'][26] = cost;
			}
			else if(op=="add"){
				is >> c >> cost;
				dist[26][c-'a'] = cost;
			}
			else if(op=="change"){
				is >> c1 >> c2 >> cost;
				dist[c1-'a'][c2-'a'] = cost;
			}
		}
	}

	void floyd(){FOR(k,27) FOR(i,27) FOR(j,27) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);}

	long long go(int s, int e){
		if(s>=e) return 0;
		long long& cache = dp[s][e];
		if(cache != -1) return cache;
		long long ret = INFL;
		FOR(i,27) ret = min(ret, go(s+1, e-1) + dist[S[s]-'a'][i] + dist[S[e]-'a'][i]);
		FOR(i,27) ret = min(ret, go(s+1, e) + dist[S[s]-'a'][i] + dist[26][i]);
		FOR(i,27) ret = min(ret, go(s, e-1) + dist[S[e]-'a'][i] + dist[26][i]);
		return cache = ret;
	}

	int getMinimumCost(string word, vector <string> operations){
		memset(dp,-1,sizeof(dp));
		memset(dist,0x2a,sizeof(dist));
		FOR(i,27) dist[i][i] = 0;
		N = word.size();
		S = word;
		read(operations);
		floyd();
		long long ret = go(0,N-1);
		if(ret >= INFL) ret = -1;
		return (int)ret;
	}
};