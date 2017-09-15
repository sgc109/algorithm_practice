// #include <bits/stdc++.h>
// #include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
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
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

double dp[2001][2001];
int N,M,T;
int main() {
	freopen("output.txt","w",stdout);
	inp1(T);
	REP(t,1,T){
		FOR(i,2001) FOR(j,2001) dp[i][j]=0;
		dp[0][0]=1;
		inp2(N,M);
		REP(i,1,N){
			FOR(j,i){
				dp[i][j]=dp[i-1][j]*(1.0/(M-j+N-i+1))*(N-i+1)+(j>0?dp[i][j-1]:0)*(1.0/(M-j+N-i+1))*(M-j+1);
			}
		}
		printf("Case #%d: %.8lf\n",t,dp[N][M]);
	}
	return 0;
}
