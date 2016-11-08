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
const int MAX_N = 52;
const int MAX_D = 102;

int degree[MAX_N];
double dp[MAX_D][MAX_N];
int adj[MAX_N][MAX_N];
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(degree,0,sizeof(degree));
		int N,D,S;
		inp3(N,D,S);
		FOR(i,N){
			FOR(j,N){
				inp1(adj[i][j]);
				if(adj[i][j]) degree[i]++;
			}
		}
		FOR(i,D+1){
			FOR(j,N){
				dp[i][j]=0.0;
			}
		}
		dp[0][S]=1.0;
		FOR(i,D){
			FOR(j,N){
				FOR(k,N){
					if(!adj[j][k]) continue;
					dp[i+1][k] += dp[i][j]/degree[j];
				}
			}
		}
		int t;
		inp1(t);
		while(t--){
			int tmp;
			inp1(tmp);
			printf("%.8lf ",dp[D][tmp]);
		}
		printf("\n");
	}
	return 0;
}