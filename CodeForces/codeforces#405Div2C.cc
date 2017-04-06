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

int n,k;
string ans[53];
vector<string> strs;
int main() {
	FOR(i,26) {
		stringstream ss;
		string tmp;
		char c = 'A'+i;
		ss << c;
		ss >> tmp;
		strs.pb(tmp);
	}
	FOR(i,26) {
		stringstream ss;
		string tmp;
		char c = 'a'+i;
		ss << c;
		ss >> tmp;
		strs.pb("A"+tmp);
	}
	cin >> n >> k;
	FOR(i,k-1){
		ans[i] = strs.back();
		strs.pop_back();
	}
	for(int i = 0; i < n - k + 1; i++){
		string yesno;
		cin >> yesno;
		if(yesno=="NO"){
			ans[i+k-1] = ans[i];
		}
		else if(yesno=="YES"){
			ans[i+k-1] = strs.back();
			strs.pop_back();
		}
	}
	FOR(i,n){
		cout << ans[i] << " " ;
	}
	return 0;
}
