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
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1002;

int dp[MAX_N][2];
int main() {
	freopen("output.txt","wb",stdout);
	int T;
	inp1(T);
	FOR(t,T){
		memset(dp,0x3a,sizeof(dp));
		string S;
		cin >> S;
		dp[0][0] = (S[0]!='-');
		dp[0][1] = (S[0]!='+');
		REP(i,1,S.size()){
			if(S[i]=='-'){
				dp[i][0] = min(dp[i-1][0],dp[i-1][1]+1);
				dp[i][1] = min(dp[i-1][0]+1,dp[i-1][1]+2);
			}
			else if(S[i]=='+'){
				dp[i][0] = min(dp[i-1][0]+2,dp[i-1][1]+1);
				dp[i][1] = min(dp[i-1][0]+1,dp[i-1][1]);
			}
		}
		printf("Case #%d: %d\n",t+1,dp[S.size()-1][1]);
	}
	return 0;
}