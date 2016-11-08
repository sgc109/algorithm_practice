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

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int dp[MAX_N][MAX_N];
char strA[MAX_N];
char strB[MAX_N];
int lenA, lenB;
int n;
int solve(int posA, int posB){
	if(posA==lenA && posB==lenB) return 1;
	if(posA==lenA) return 0;
	if(posB==lenB) {
		if(strA[posA]=='*') return solve(posA+1,posB);
		else return 0;
	}

	int& cache = dp[posA][posB];
	if(cache != -1) return cache;
	
	int ret=0;
	if(strA[posA]=='*'){
		ret |= solve(posA+1,posB);
		ret |= solve(posA,posB+1);
	}
	else if(strA[posA]=='?') ret |= solve(posA+1,posB+1);
	else if(strA[posA]==strB[posB]) ret |= solve(posA+1,posB+1);
	return cache = ret;
}

int main() {
	int T;
	inp1(T);
	while(T--){
		scanf("%s",strA);
		lenA = strlen(strA);
		inp1(n);
		vector<string> v;
		while(n--){
			scanf("%s",strB);
			lenB = strlen(strB);
			memset(dp,-1,sizeof(dp));
			if(solve(0,0)) v.pb(strB);
		}
		sort(v.begin(),v.end());
		FOR(i,v.size()){
			cout << v[i];
			printf("\n");
		}
	}
	return 0;
}