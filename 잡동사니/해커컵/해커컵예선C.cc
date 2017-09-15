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
#include <deque>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i)
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

double dp[30][500];
char buf[100];
double coff[500];
double solve(int n, int sum, int limit){
	if(n==1) return 1<=sum&&sum<=limit;
	double& cache = dp[n][sum];
	if(cache!=-1.0) return cache;
	double ret=0;
	for(int i = 1; i < sum; i++){
		ret+=solve(n/2,i,limit)*solve((n+1)/2,sum-i,limit);
	}
	return cache=ret;
}

int main() {
	int T;
	inp1(T);
	FOR(t,T){
		int H,S;
		inp2(H,S);
		double ans=0.0;
		FOR(i,S){
			// 초기화
			FOR(i,30) FOR(j,500) dp[i][j]=-1.0;

			// 입력처리
			scanf("%s",buf);
			int len = strlen(buf);
			int sum=0;
			int pos=0;
			for(pos;pos<len&&buf[pos]!='d';pos++) sum=sum*10+buf[pos]-'0';
			int cnt=sum;
			for(sum=0,++pos;pos<len&&buf[pos]!='+'&&buf[pos]!='-';pos++) sum=sum*10+buf[pos]-'0';
			int dice=sum;
			int add=0;
			bool isAdd=(len!=pos);
			bool minus=false;
			if(isAdd){
				minus=buf[pos]=='-';
				for(sum=0,++pos;pos<len;pos++) sum=sum*10+buf[pos]-'0';
				add=sum*(minus?-1:1);
			}

			// 확률계산(dp)
			double det=1;
			FOR(j,cnt) det*=dice;
			for(int j=cnt;j<=dice*cnt;j++) coff[j]=solve(cnt,j,dice)/det;

			// 가능한 데미지 범위계산
			int lo=1*cnt,hi=dice*cnt;
			lo+=add,hi+=add;
			lo=max(lo,H);
			if(lo>hi) continue;

			// 가능한 데미지들의 확률 합 계산
			double sumD=0.0;
			for(int j=lo;j<=hi;j++){
				if(j-add<cnt||dice*cnt<j-add) continue;
				sumD+=coff[j-add];
			}
			ans=max(ans,sumD);
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
