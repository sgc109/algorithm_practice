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
#include <unordered_set>
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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int n,m;
char Sbuf[1000002],Pbuf[102];
ll Hash[2] = {1000000007,1000000009};
ll g[5][1002][2];
int f[130];
char chs[5]="AGCT";
ll str2hash(string &S){
	int len = S.size();
	ll ret[2]={0,};
	FOR(k,2){
		FOR(i,len){
			ret[k] = (ret[k]*1023)%Hash[k];
			ret[k] = (ret[k]+f[S[i]])%Hash[k];
		}
	}
	return ret[0]*Hash[1]+ret[1];
}
int main() {
	f['T']=4;f['A']=1;f['G']=2;f['C']=3;
	FOR(k,2){
		FOR(i,4){
			g[f[chs[i]]][0][k] = f[chs[i]];
			FOR(j,1000){
				g[f[chs[i]]][j+1][k]=(g[f[chs[i]]][j][k]*1023)%Hash[k];
			}
		}
	}
	int T;
	inp1(T);
	while(T--){
		int ans=0;
		inp2(n,m);
		unordered_set<ll> us;
		scanf("%s %s",Sbuf,Pbuf);
		if(n<m) {
			printf("0\n");
			continue;
		}
		string S(Sbuf),P(Pbuf);
		vector<string> vs;
		vs.pb(P);
		FOR(i,m-1){
			for(int j = i+1; j < m; j++){
				string A = P.substr(0,i);
				string B = P.substr(i,j-i+1);
				string C = P.substr(j+1,m-j-1);
				reverse(B.begin(),B.end());
				string newS = A+B+C;
				vs.pb(newS);				
			}
		}
		FOR(i,vs.size()) {
			ll add = str2hash(vs[i]);
			if(!us.count(add)) us.insert(add);
		}
		ll sum[2]={0,};
		FOR(k,2){
			FOR(i,m){
				sum[k] = (sum[k]*1023)%Hash[k];
				sum[k] = (sum[k]+f[S[i]])%Hash[k];
			}
		}
		if(us.count(sum[0]*Hash[1]+sum[1])) ans++;
		for(int i = m; i < n; i++){
			FOR(k,2){
				sum[k] = (sum[k]-g[f[S[i-m]]][m-1][k]+Hash[k])%Hash[k];
				sum[k] = (sum[k]*1023)%Hash[k];
				sum[k] = (sum[k]+f[S[i]])%Hash[k];
			}
			if(us.count(sum[0]*Hash[1]+sum[1])) ans++;
		}
		printf("%d\n",ans);
	}	
	return 0;
}