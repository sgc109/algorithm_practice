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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
string A,B,NA,NB;
int gcd(int a, int b){
	if(!a||!b) return a+b;
	return gcd(b%a,a);
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
void NO(){printf("0");exit(0);}
int main() {
	cin >> A >> B;
	FOR(i,lcm(sz(A),sz(B))/sz(A)) NA+=A;
	FOR(i,lcm(sz(A),sz(B))/sz(B)) NB+=B;
	FOR(i,sz(NA)){
		if(NA[i]!=NB[i]) NO();
	}
	printf("1");
	return 0;
}
