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

struct point{
	int x,y;
	// bool operator<(const point& rhs) const{
	// 	if(x==rhs.x) y<rhs.y;
	// 	return x>rhs.x;
	// }
};
bool cmp(const point& lhs, const point& rhs) {
	if(lhs.x==rhs.x) return lhs.y < rhs.y;
	return lhs.x > rhs.x;
}
int N;
ll t[75003];
point points[75003];
void update(int pos, int v){
	while(pos<=N){
		t[pos]+=v;
		pos+=pos&-pos;
	}
}
ll query(int pos){
	ll ret=0;
	while(pos>=1){
		ret+=t[pos];
		pos-=pos&-pos;
	}
	return ret;
}
void compressing(){
	vi sortedX, sortedY;
	unordered_set<int> usX;
	unordered_set<int> usY;
	FOR(i,N){
		int xx = points[i].x;
		int yy = points[i].y;
		if(!usX.count(xx)) usX.insert(xx), sortedX.pb(xx);
		if(!usY.count(yy)) usY.insert(yy), sortedY.pb(yy);
	}
	sort(all(sortedX));
	sort(all(sortedY));
	FOR(i,N){
		int& xx = points[i].x;
		int& yy = points[i].y;
		xx = lower_bound(all(sortedX),xx)-sortedX.begin()+1;
		yy = lower_bound(all(sortedY),yy)-sortedY.begin()+1;
	}
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(t,0,sizeof(t));
		ll ans=0;
		inp1(N);
		FOR(i,N){
			int xx,yy;
			inp2(xx,yy);
			points[i] = point{xx,yy};
		}
		compressing();
		sort(points,points+N,cmp);
		FOR(i,N){
			ll q = query(points[i].y);
			ans+=q;
			update(points[i].y,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
