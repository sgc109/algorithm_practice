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

int N,M;
char pane[30][15];
int D[1<<10][250];
int isOn(int bit, int pos){
	return bit&(1<<pos);
}
int go(int state, int pos){
	state%=1024;
	// printf("state:%d, pos:%d\n",state,pos);
	if(pos>=N*M) return 0;
	int& cache = D[state][pos];
	if(cache!=-1) return cache;
	int ret=0;
	ret=max(ret,go(state<<1,pos+1)+(pane[pos/M][pos%M]=='1'));
	if(pane[pos/M][pos%M]=='1') return cache=ret;
	ret=max(ret,1+go((state<<1)|1,pos+1));
	if(pos%M<M-1 && pos/M>0 && !isOn(state,M-1) && !isOn(state,M-2) && pane[(pos+1)/M][(pos+1)%M]!='1' && pane[(pos-M)/M][(pos-M)%M]!='1' && pane[(pos-M+1)/M][(pos-M+1)%M]!='1'){
		// printf("state:%d, pos:%d\n",state,pos);
		ret=max(ret,16+go((state<<2)|3,pos+2));
	}
	return cache=ret;
}
int main() {
	memset(D,-1,sizeof(D));
	cin >> N >> M;
	FOR(i,N) FOR(j,M) scanf(" %c",&pane[j][i]);
	swap(N,M);
	cout << go(0,0);
	return 0;
}
