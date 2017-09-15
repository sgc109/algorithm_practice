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

int H[43];
int N;
int ans,now;
int cnt[43];
void NO(){
	printf("0");
	exit(0);
}
int main() {
	inp1(N);
	FOR(i,N) inp1(H[i]);
	sort(H,H+N);
	FOR(i,N-1) if(H[i+1]-H[i]>1) NO();
	FOR(i,N) {
		cnt[H[i]]++;
		if(cnt[H[i]]>2) NO();
	}
	if(!cnt[0]) NO();
	int UP=-1;
	FOR(i,N) UP=max(UP,H[i]);
	int pos;
	for(pos=0;pos<=UP;pos++) if(cnt[pos]==1) break;
	REP(i,pos+1,UP) if(cnt[i]>1) NO();
	ans=1;
	FOR(i,UP+1){
		ans*=2;
		if(cnt[i]==1) break;
	}
	printf("%d",ans);
	return 0;
}
