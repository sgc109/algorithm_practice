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
const int MAX_N = 102;

int notPrime[20];
double probA, probB;
double dp[20][20][20];
int n;
// round x 5 분 ~ round x 5 + 5 분 이고 현재 A팀과 B팀의 골넣은 횟수가 주어질때 최종적으로 A팀과 B팀중 적어도 한팀은 소수 개의 골을 기록할 확률
double solve(int round, int cntA, int cntB){
	if(round==n) return (!notPrime[cntA] || !notPrime[cntB]);
	double& cache = dp[round][cntA][cntB];
	if(cache != -1) return cache;
	double ret=0;
	ret += solve(round+1,cntA,cntB) * (1-probA) * (1-probB);
	ret += solve(round+1,cntA,cntB+1) * (1-probA) * probB;
	ret += solve(round+1,cntA+1,cntB) * probA * (1-probB);
	ret += solve(round+1,cntA+1,cntB+1) * probA * probB;

	return cache = ret;
}

int main() {
	FOR(i,20)FOR(j,20)FOR(k,20)dp[i][j][k]=-1;
	n=18;
	notPrime[0] = notPrime[1] = 1;
	for(int i = 2; i * i <= n; ++i){
		if(notPrime[i]) continue;
		for(int j = 2*i; j <= n; j+=i){
			notPrime[j] = 1;
		}
	}

	scanf("%lf%lf",&probA,&probB);
	probA /= 100;
	probB /= 100;
	printf("%lf",solve(0,0,0));
	return 0;
}