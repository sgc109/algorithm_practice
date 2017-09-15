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
const int MAX_N = 10002;

double dp[MAX_N][2];
double X[MAX_N];
double Y[MAX_N][2];
int canGo[MAX_N][2][MAX_N][2];
int canGoFromS[MAX_N][2];
int canGoToE[MAX_N][2];
int n;
int s,e;
void figureCanGOStraight(){
	FOR(i,n-1){
		REP(j,i+1,n){
			FOR(l,4){
				canGo[i][l/2][j][l%2] = 0;
				if(i+1==j) canGo[i][l/2][j][l%2] = 1;
				bool find=true;
				REP(k,i+1,j){
					if(!((Y[j][l%2]-Y[i][l/2])*(X[k]-X[i]) > (X[j]-X[i])*(Y[k][0]-Y[i][l/2]) &&
						(Y[j][l%2]-Y[i][l/2])*(X[k]-X[i]) < (X[j]-X[i])*(Y[k][1]-Y[i][l/2]))) {find=false;break;}
				}
			if(find) canGo[i][l/2][j][l%2] = 1;
		}
	}
}
}

double solve(int pos, int updown){
	if(pos==n) return 0.0;
	double ret=10000000000000000;
	if(canGoToE[pos][updown]) ret = min(ret, X[n-1]-X[pos]);
	REP(i,pos+1,n){
		FOR(k,2){
			if(canGo[pos][updown][i][k]) {
				double& cache = dp[i][k];
				if(cache==-1) cache = solve(i,k);
				ret = min(ret, sqrt(pow(X[pos]-X[i],2)+pow(Y[pos][updown]-Y[i][k],2))+cache);
			}
		}
	}

	return ret;
}

int main() {
	FILE *fp = stdout;
	// FILE *fp = fopen("output.txt","wb");
	int T;
	inp1(T);
	// printf("total Case:%d\n",T);
	FOR(t,T){
		// printf("%dth test...",t+1);
		memset(canGoFromS,0,sizeof(canGoFromS));
		memset(canGoToE,0,sizeof(canGoToE));
		inp1(n);
		FOR(i,n){
			scanf("%lf",&X[i]);
			scanf("%lf",&Y[i][0]);
			scanf("%lf",&Y[i][1]);
		}
		figureCanGOStraight();
		// FOR(i,n-1){
		// 	REP(j,i+1,n){
		// 		FOR(k,4){
		// 			printf("%d(%d)->%d(%d) staight:%d\n",i,k/2,j,k%2,canGo[i][k/2][j][k%2]);
		// 		}
		// 	}
		// }
		double lo = Y[0][0]; double hi = Y[0][1];
		canGoFromS[0][0] = canGoFromS[0][1] = 1;
		REP(i,1,n){
			if(Y[i][1] < lo || hi < Y[i][0]) break;
			if(lo <= Y[i][0] && Y[i][0] <= hi) canGoFromS[i][0] = 1;
			if(lo <= Y[i][1] && Y[i][1] <= hi) canGoFromS[i][1] = 1;
			lo = max(lo, Y[i][0]);
			hi = min(hi, Y[i][1]);
		}
		// FOR(i,n){
		// 	FOR(k,2){
		// 		printf("%d -> %d(%d) straight : %d\n",0,i,k,canGoFromS[i][k]);
		// 	}
		// }
		lo = Y[n-1][0]; hi = Y[n-1][1];
		canGoToE[n-1][0] = canGoToE[n-1][1] = 1;
		for(int i = n-2; i >= 0; --i){
			if(Y[i][1] < lo || hi < Y[i][0]) break;
			if(lo <= Y[i][0] && Y[i][0] <= hi) canGoToE[i][0] = 1;
			if(lo <= Y[i][1] && Y[i][1] <= hi) canGoToE[i][1] = 1;
			lo = max(lo, Y[i][0]);
			hi = min(hi, Y[i][1]);
		}
		// FOR(i,n){
		// 	FOR(k,2){
		// 		printf("%d(%d) -> %d straight : %d\n",i,k,n-1,canGoToE[i][k]);
		// 	}
		// }

		double dist=10000000000000000;

		int s0=-1,s1=-1;
		for(int i = n-1; i >=0; --i){
			if(canGoFromS[i][0] && s0==-1) s0=i;
			if(canGoFromS[i][1] && s1==-1) s1=i;
		}
		FOR(ii,MAX_N){
			dp[ii][0]=-1;dp[ii][1]=-1;
		}
		dist = min(dist, solve(0,1));
		dist = min(dist, solve(0,0));
		dist = min(dist, X[s0]-X[0]+solve(s0,0));
		dist = min(dist, X[s1]-X[0]+solve(s1,1));

		fprintf(fp,"%.2lf\n",dist);
		// printf("good job!\n");
	}

	return 0;
}