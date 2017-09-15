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
#define REP(i,a,b) for(int i = a; i < b;++i)
#define FOR(i,n) REP(i,0,n)
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

string S;
int n,r;
vi pp,prv,cur;
int check[18];
int main() {
	cin >> S >> r;
	n = S.size();
	ll det = 0;
	ll num = 0;
	FOR(i,1<<n){
		pp=vi(n,0);
		prv=vi(n,0);
		int on=0;
		for(int j=i;j;on+=(j&1),j>>=1){}
			if(on!=r) continue;
		det++;
		int id=1;
		FOR(j,n) if(i&(1<<j)) prv[j]=id++;
		for(int size=n; size>=3; size--){
			memset(check,0,sizeof(check));
			cur=vi(n,0);
			FOR(k,size){
				int nPos;
				if(!prv[k]) continue;
				if(k==0) nPos=1;
				else if(k>=size-2) nPos=k-1;
				else if(S[k]=='B') nPos=k+1;
				else if(S[k]=='W') nPos=k-1;
				else if(S[k]=='R'){
					if(size==n) nPos=k-1;
					else nPos=k+(pp[k+1]==prv[k]?1:-1);
				}
				check[nPos]++;
				cur[nPos]=prv[k];
			}
			FOR(k,size) if(check[k]>1) cur[k]=0;
			pp=prv;
			prv=cur;
		}
		num+=(prv[0]!=0)+(prv[1]!=0);
	}
	printf("%.10lf",(double)num/det);
	return 0;
}
