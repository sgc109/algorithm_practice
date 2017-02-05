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

int N,M,K;
int Map[53][53];
int cnt[53][53];
int dy[]={-1,0,0,1};
int dx[]={0,1,-1,0};
bool inRange(int i, int j){
	return 0<=i&&i<N&&0<=j&&j<M;
}
int main() {
	inp2(N,M);
	FOR(i,N) scanf("%s",Map[i]);
	inp1(K);
	FOR(i,N){
		FOR(j,M){
			if(Map[i][j]=='.') continue;
			FOR(k,4){
				int ni=i+dy[k];
				int nj=j+dx[k];
				if(!inRange(ni,nj)) continue;
				cnt[ni][nj]++;
			}
		}
	}
	FOR(i,N){
		FOR(j,M){
			if(cnt[])
		}
	}
	return 0;
}
