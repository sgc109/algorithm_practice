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

int T;
string S;
string solve(string& num){
	string ret =  num;
	while(1){
		if(ret.size()==1) return ret;
		bool found = false;
		for(int i = 0; i < ret.size()-1; i++){
			if(ret[i]<=ret[i+1]) continue;
			found = true;
			if(i==0 && ret[i] == '1'){
				int len = ret.size();
				ret = "";
				for(int j = 0 ; j < len-1; j++) ret += '9';
				return ret;		
			}
			else {
				int len = ret.size();
				ret[i] = ret[i] - 1;
				for(int j = i+1; j < len; j++) ret[j] = '9';
				break;
			}
		}
		if(!found) break;
	}
	return ret;
}
int main() {
	fastio();
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> S;
		string ans = solve(S);
		cout << "Case #" << t << ": " << ans << "\n";
	}	
	return 0;
}
