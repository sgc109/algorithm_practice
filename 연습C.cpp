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

priority_queue<int> pq;
int N;
string op;
int main() {
	inp1(N);
	vector<pair<string,int> > ans;
	FOR(i,N){
		cin >> op;
		int a;
		// inp1(a);
		if(op != "removeMin") inp1(a);

		if(op=="insert") pq.push(-a);
		else if(op=="removeMin"){
			if(pq.empty()) {
				ans.push_back({"insert", 1e9});
			}
			else pq.pop();
		}
		else if(op=="getMin") {
			if(pq.empty()){
				ans.pb({"insert",a});
				pq.push(-a);
			}
			else {				
				while(!pq.empty() && -pq.top() < a) {
					ans.pb({"removeMin",0});
					pq.pop();
				}				
				if(pq.empty() || (!pq.empty()&& -pq.top()!=a)){
					ans.pb({"insert", a});
					pq.push(-a);
				}
			}
		}
		ans.pb({op, a});
	}
	cout << ans.size() << "\n";
	FOR(i,sz(ans)){
		string op = ans[i].first;
		int a = ans[i].second;
		if(op=="removeMin") {
			cout << op << "\n";
			continue;
		}
		cout << op << " " << a << "\n";
	}
	return 0;
}
