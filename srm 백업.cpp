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
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
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

int N,M;
double dp[2503][2503];
double case1(double rest, double known){
	double ret = rest-2*known;
	ret /= (rest-known);
	ret /= (rest-known-1);
	return ret;
}
double case2(double rest, double known){
	double ret = rest-2*known;
	ret /= (rest-known);
	ret *= (rest-2*known-2);
	ret /= (rest-known-1);
	return ret;
}
double case3(double rest, double known){
	double ret = rest-2*known;
	ret /= (rest-known);
	ret *= known;
	ret /= (rest-known-1);
	return ret;
}
double case4(double rest, double known){
	double ret = known;
	ret /= (rest-known);
	return ret;
}

double go(int rest, int known){
	if(rest==0) return 0;
	if(rest==2) return 1;
	double& cache = dp[rest][known];
	if(cache != -1) return cache;
	double ret = 0;
	if(rest/2 > known){
		if(rest - 2*known > 0 && rest - 2*known - 1 > 0)
			ret += case1(rest, known) * (go(rest-2, known) + 1);
		if(rest - 2*known - 2 > 0) 
			ret += case2(rest, known) * (go(rest, known+2) + 1);
		if(rest - 2*known > 0 && rest - 2*known - 1 > 0 && known > 0) 
			ret += case3(rest, known) * (go(rest-2, known) + 2);
		if(known > 0) 
			ret += case4(rest ,known) * (go(rest-2, known-1) + 1);
	}
	else ret += (go(rest-2, known-1) + 1);
	return cache = ret;
}
int main() {
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i <= 2500; i++){
		for(int j = 0 ; j <= 2500; j++){
			dp[i][j] = -1;
		}
	}
	cout << go(N*M,0);
	
	return 0;
}
