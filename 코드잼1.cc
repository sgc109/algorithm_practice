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
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int main() {
	freopen("codejam.txt","r",stdin);
	freopen("output.txt","wb",stdout);
	int T;
	inp1(T);
	FOR(t,T){
		string str;
		cin >> str;
		int len = str.size();
		int cntB=0;
		FOR(i,len){
			if(str[i]=='B') cntB++;
		}
		ll I,J;
		scanf("%lld%lld",&I,&J);
		ll diff = J-I+1;
		ll ans=0;
		ans+=(diff/len)*cntB;
		int start = (I-1)%len;
		int rest = diff%len;
		str+=str;
		REP(i,start,start+rest){
			if(str[i]=='B') ans++;
		}
		printf("Case #%d: %lld\n",t+1,ans);
	}
	
	return 0;
}