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

enum{BLACK=0,ODD,EVEN};

int N,M;
ll D[1<<16][801];
int changeBit(int bit, int obPos, int kind){
	return (bit^(bit&(3<<(obPos<<1))))|(kind<<(obPos<<1));
}
int state(int bit, int obPos){
	return (bit>>(obPos<<1))&3;
}
int onBit(int bit, int kind, bool leftMost){
	if(kind>BLACK&&!leftMost) bit=changeBit(bit,0,(state(bit,0)==BLACK)?BLACK:3-state(bit,0));
	return ((bit<<2)|kind)&((1<<(M<<1))-1);
}
ll go(int bit, int pos){
	bool leftMost=(pos%M)==0;
	if(pos==N*M) return 1;
	ll& ret=D[bit][pos];
	if(ret!=-1) return ret;
	ret=0;
	if(state(bit,M-1)==BLACK) {
		if(pos/M < N-1 || (leftMost||state(bit,0)==BLACK||state(bit,0)==ODD)) ret+=go(onBit(bit,(leftMost?EVEN:(state(bit,0)>BLACK?ODD:EVEN)),leftMost),pos+1);
		if(pos/M < N-1 || (leftMost||state(bit,0)==BLACK||state(bit,0)==EVEN)) ret+=go(onBit(bit,BLACK,leftMost),pos+1);
	}
	else if(state(bit,M-1)==EVEN) {
		if(pos/M < N-1 || (leftMost||state(bit,0)==BLACK||state(bit,0)==EVEN)) ret+=go(onBit(bit,BLACK,leftMost),pos+1);
	}
	else if(state(bit,M-1)==ODD) {
		if(pos/M < N-1 || (leftMost||state(bit,0)==BLACK||state(bit,0)==ODD)) ret+=go(onBit(bit,(leftMost?ODD:ODD+(state(bit,0)>BLACK)),leftMost),pos+1);
	}
	return ret%MOD;
}
int main() {
	memset(D,-1,sizeof(D));
	inp2(N,M);
	cout << go(0,0);
	return 0;
}