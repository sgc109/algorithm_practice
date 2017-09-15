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

string S1,S2;
int D[53][53][2];
int go(int l, int r, int rev){
	string tmp=S2.substr(l,r-l+1);
	if(rev) reverse(all(tmp));
	if(r-l+1==sz(S1)) return tmp==S1;
	int& cache = D[l][r][rev];
	if(cache!=-1) return cache;
	int ret=0;
	if(tmp.back()=='A'){
		if(rev) ret=go(l+1,r,rev);
		else ret|=go(l,r-1,rev);
	}
	if(tmp[0]=='B'){
		if(rev) ret|=go(l,r-1,rev^1);
		else ret|=go(l+1,r,rev^1);
	}
	return cache=ret;
}
int main() {
	memset(D,-1,sizeof(D));
	cin >> S1 >> S2;
	cout << go(0,sz(S2)-1,0);
	return 0;
}
