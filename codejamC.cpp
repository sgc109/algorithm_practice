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

ll T, N, K;
ll calcMin(ll len){
	return len % 2 ? len/2 : (len-1)/2;
}
ll calcMax(ll len){
	return len/2;
}
struct range{
	ll s, e;
	ll maxD, minD;
	ll len;
	range(ll _s, ll _e){
		s = _s;
		e = _e;
		len = e - s - 1;
		maxD = calcMax(len);
		minD = calcMin(len);
	}
	bool operator<(const range& rhs)const {
		if(min(minD, maxD) != min(rhs.minD, rhs.maxD)) return min(minD, maxD) < min(rhs.minD, rhs.maxD);
		if(max(minD, maxD) != max(rhs.minD, rhs.maxD)) return max(minD, maxD) < max(rhs.minD, rhs.maxD);
		return s > rhs.s;
	}
};

priority_queue<range> pq;
int main() {
	freopen("C-large-practice.in","r",stdin);
	freopen("output.txt","w",stdout);
	fastio();
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		cin >> N >> K;
		while(!pq.empty()) pq.pop();
		pq.push(range(0, N+1));
		for(int i = 0 ; i < K-1; i++){
			range tp = pq.top();
			pq.pop();
			int m = tp.s + (tp.len + 1) / 2;
			pq.push(range(tp.s, m));
			pq.push(range(m, tp.e));
		}
		range tp = pq.top();
		pq.pop();
		cout << "Case #" << t << ": " << max(tp.maxD, tp.minD) << " " << min(tp.maxD, tp.minD) << "\n";
	}
	return 0;
}
