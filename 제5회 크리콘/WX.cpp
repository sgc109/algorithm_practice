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

int N,K;
ll T;
int main() {
	inp2(N,K);
	vector<int> A(N);
	vector<int> B(N);
	vector<int> first(N);
	scanf("%lld",&T);
	FOR(i,N) inp1(A[i]);
	first = A;
	ll t;
	for(t = 0; t < T; t++){
		B = vector<int>(N,0);
		FOR(i,N){
			FOR(j,K){
				B[i] ^= A[(i+j)%N];
			}
		}
		A = B;
		if(A == first) break;
	}

	if(t == T) {
		FOR(i,N) printf("%d ",A[i]);
		return 0;
	}

	t++;
	T %= t;

	A = first;
	for(t = 0; t < T; t++){
		B = vector<int>(N,0);
		FOR(i,N){
			FOR(j,K){
				B[i] ^= A[(i+j)%N];
			}
		}
		A = B;
	}

	FOR(i,N) printf("%d ",A[i]);

	return 0;
}
