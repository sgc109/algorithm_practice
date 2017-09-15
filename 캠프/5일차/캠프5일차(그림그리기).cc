#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
#include <deque>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i <= b;++i)
#define FOR(i,n) REP(i,0,n-1)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M,T;
char map[153][153];
ll inc[53][30];
ll incS[53][30];
char pic[53][53];
ll ansR,ansG,ansB;
ll addR,addG,addB;
void precalc(){
	ll cnt[30];
	memset(cnt,0,sizeof(cnt));
	FOR(k,min(min(N,M),T)){
		FOR(i,N){
			FOR(j,M){
				if(map[i+k][j+k]==pic[i][j]) continue;
				if(map[i+k][j+k]!='.' && pic[i][j]!='.') cnt[map[i+k][j+k]-'A']--;
				if(pic[i][j]!='.') cnt[pic[i][j]-'A']++;
				if(pic[i][j]!='.') map[i+k][j+k]=pic[i][j];
			}
		}
	}
	if(min(N,M)>=T) {
		printf("%lld\n%lld\n%lld",cnt['R'-'A'],cnt['G'-'A'],cnt['B'-'A']);
		exit(0);
	}
	ansR=cnt['R'-'A'];
	ansG=cnt['G'-'A'];
	ansB=cnt['B'-'A'];
	int k=min(N,M);
	int R=cnt['R'-'A'],G=cnt['G'-'A'],B=cnt['B'-'A'];
	FOR(i,N){
		FOR(j,M){
			if(map[i+k][j+k]==pic[i][j]) continue;
			if(map[i+k][j+k]!='.' && pic[i][j]!='.') cnt[map[i+k][j+k]-'A']--;
			if(pic[i][j]!='.') cnt[pic[i][j]-'A']++;
			if(pic[i][j]!='.') map[i+k][j+k]=pic[i][j];	
		}
		addR=cnt['R'-'A']-R;
		addG=cnt['G'-'A']-G;
		addB=cnt['B'-'A']-B;
	}
}
int main() {
	memset(map,'.',sizeof(map));
	inp3(N,M,T);
	FOR(i,N) scanf("%s",pic[i]);
	precalc();
	ll more=T-min(N,M);
	printf("%lld\n%lld\n%lld",ansR+addR*more,ansG+addG*more,ansB+addB*more);
	return 0;
}
