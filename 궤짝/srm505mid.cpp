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
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class SetMultiples{
public:
	long long smallestSubset(long long A, long long B, long long C, long long D){
		A = max(A,B/2+1), C = max(C,D/2+1);
		long long ans = B-A+1+D-C+1;
		while(A<=B){
			long long k = (C+B-1)/B;
			long long l = max(A,(C+k-1)/k);
			long long r = min(D/k,B);
			if(l<=r) ans -= r-l+1;
			B = l-1;

		}
		return ans;
	}
};
int main() {
	SetMultiples obj;
	cout << obj.smallestSubset(53243, 11124726, 10000000000, 10000000000);
	return 0;
}
