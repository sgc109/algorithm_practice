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
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

long long S,T;
map<long long,int> mp;
int main() {
	// printf("%d %d %d %d",'*','+','-','/');
	cin >> S >> T;
	if(S==T) {
		printf("0");
		return 0;
	}
	queue<pair<long long, string> > q;
	q.push({S,""});
	mp[S]=1;
	string ans=".";
	while(!q.empty()){
		long long here=q.front().first;
		string state=q.front().second;
		// cout << "here : " << here << ", state : " << state << endl;
		q.pop();
		if(here>1e9) continue;
		if(here==T) {	
			ans=state;
			break;
		}
		if(mp.count(here*here)==0) q.push({here*here,state+"*"}),mp[here*here]=1;
		if(mp.count(here+here)==0) q.push({here+here,state+"+"}),mp[here+here]=1;
		if(mp.count(1)==0) q.push({1,state+"/"}),mp[1]=1;
	}
	if(ans==".") printf("-1");
	else cout << ans;
	return 0;
}	
