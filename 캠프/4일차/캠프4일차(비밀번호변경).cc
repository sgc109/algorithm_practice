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

string S;
int K;
int main() {
	cin >> S >> K;
	int N = S.size();
	int pos=N-K;
	int ans=0;
	if(N==K){
		printf("0");
		return 0;
	}
	if(K<=N/2){
		FOR(i,K) if(S[i]!=S[pos+i]) ans++;
		printf("%d",ans);
		return 0;
	}
	int e=2*K-N;
	int f=K-e;
	// printf("e:%d, f:%d\n",e,f);
	FOR(i,f){
		// printf("i:%d, ans:%d\n",i,ans);
		if(N-1-i-f<0) ans+=(S[N-1-i]!=S[N-1-i-f]);
		else{
			int cnt[26];
			memset(cnt,0,sizeof(cnt));
			int j;
			for(j=N-1-i; j>=f; j-=f){
				cnt[S[j]-'a']++;
				// printf("%c ",S[j]);
			}
			if(j>=0) cnt[S[j]-'a']++;
			// printf("%c ",S[j]);
			// printf("\n");
			int maxC=0,maxA;
			FOR(j,26) if(maxC<cnt[j]) maxC=cnt[j],maxA=j;
			// printf("max:%c\n",'a'+maxA);
			for(j=N-1-i; j>=f; j-=f){
				if(S[j]!=maxA+'a') ans++;
			}
			if(j>=0) if(S[j]!=maxA+'a') ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
