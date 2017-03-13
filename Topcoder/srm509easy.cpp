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
const int MOD = 9;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class LuckyRemainder{
public:
	int N;
	int comb[53][53];
	int pow2[53];
	int go(int n, int r){
		r = min(r,n-r);
		if(r==0) return 1;
		int& cache = comb[n][r];
		if(cache!=-1) return cache;
		return cache = (go(n-1,r) + go(n-1,r-1))%MOD;
	}
	int getLuckyRemainder(string X){
		memset(comb,-1,sizeof(comb));
		pow2[0]=1;
		REP(i,1,52) pow2[i] = (pow2[i-1] * 2) % MOD;
		int ans = 0;
		N = sz(X);
		for(int i = 0; i < N; i++){
			for(int j = i ; j < N; j++){
				int a = i;
				int b = j-i;
				ans = (ans + pow2[a] * go(N-a-1,b) * (X[i]-'0')) % MOD;
			}
		}
		return ans;
	}
};