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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 4002;

int dp[MAX_N][MAX_N];
char s1[MAX_N],s2[MAX_N];
int main() {
	scanf("%s %s",s1,s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int ans = 0;
	FOR(i,len1){
		FOR(j,len2){
			if(s1[i]==s2[j]) {
				dp[i][j] = (i==0||j==0 ? 0 : dp[i-1][j-1]) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}