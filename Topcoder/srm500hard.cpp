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
const int MOD = 500500573;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

ll inv[3003];
ll fact[3003];
ll base10[3003];
class ProductAndSum{
public:
	ll sqrN(int x, int n){
		if(n==0) return 1;
		if(n%2==1){
			ll tmp = sqrN(x,(n-1)/2) % MOD;
			tmp = (tmp*tmp) % MOD;
			return (x*tmp) % MOD;
		}
		ll tmp = sqrN(x,n/2) % MOD;
		return (tmp*tmp) % MOD;
	}
	ll go(vi& v, int sum){
		if(v[2] < 0 || v[3] < 0 || v[5] < 0 || v[7] < 0 || sum < 0) return 0;

		ll ret = 0;
		ll cnt = 0;
		ll lower = 1;
		v[1] = sum;
		REP(i,1,9) if(v[i]>0) cnt+=v[i], lower = (lower * inv[v[i]]) % MOD;
		ll acc = 0;
		REP(j,1,9){
			if(v[j]==0) continue;
			ll tmp = (j) % MOD;
			tmp = (tmp * fact[cnt-1]) % MOD;
			tmp = (tmp * lower) % MOD;
			tmp = (tmp * fact[v[j]]) % MOD;
			tmp = (tmp * inv[v[j]-1]) % MOD;
			acc = (acc + tmp) % MOD;
		}
		FOR(i,cnt) ret = (ret + (acc * base10[i]) % MOD) % MOD;
		v[2]-=2, v[4]++;
		ret += go(v, sum);
		v[2]+=2, v[4]--;

		v[2]--, v[3]--, v[6]++;
		ret += go(v, sum-1);
		v[2]++, v[3]++, v[6]--;

		v[2]-=3, v[8]++;
		ret += go(v, sum-2);
		v[2]+=3, v[8]--;

		v[3]-=2, v[9]++;
		ret += go(v, sum-3);
		v[3]+=2, v[9]--;
		return ret % MOD;
	}
	int getSum(int p2, int p3, int p5, int p7, int S){
		fact[0] = fact[1] = 1;
		REP(i,2,3000) fact[i] = (fact[i-1] * i) % MOD;
		REP(i,0,3000) inv[i] = sqrN(fact[i], MOD-2);
		base10[0] = 1;
		REP(i,1,3000) base10[i] = (base10[i-1] * 10) % MOD;
		vi v(10,0);
		int sum=2*p2+3*p3+5*p5+7*p7;
		v[2] = p2, v[3] = p3, v[5] = p5, v[7] = p7;
		ll ret = go(v,S-sum);
		return (int)ret;
	}
};

int main(){
	ProductAndSum obj;
	cout << obj.getSum(
		5,
		5,
		5,
		5,
		100
		);
	return 0;
}