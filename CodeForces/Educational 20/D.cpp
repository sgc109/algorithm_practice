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

string str;
int K;
vi cut;
bool possi(int w){
	int cnt = 0;
	int prev = -1;
	for(int i = 0 ; i < sz(cut); i++){
		if(cut[i] - prev - (i==sz(cut)-1) > w) {
			cnt++;
			if(i==0) return false;
			if(prev == cut[i-1]) return false;
			prev = cut[i-1];
			if(cut[i] - prev - (i==sz(cut)-1) > w) return false;
		}
	}
	cnt++;
	return cnt <= K;
}
int main() {
	scanf("%d\n",&K);
	getline(cin,str);
	str += ' ';
	int len = str.size();
	FOR(i,len) if(str[i] == ' ' || str[i] == '-') cut.pb(i);
	int lo = 0, hi = 1e8;
	while(lo<hi){
		int mid = (lo+hi) >> 1;
		if(!possi(mid)) lo = mid+1;
		else hi = mid;
	}

	printf("%d\n",lo);

	return 0;
}
