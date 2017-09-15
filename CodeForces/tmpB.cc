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

int check[26];
vector<pii> ans;
void NO(){
	printf("-1");
	exit(0);
}
int main() {
	memset(check,-1,sizeof(check));
	string S1,S2;
	cin >> S1 >> S2;
	FOR(i,S1.size()){
		int a = S1[i]-'a';
		int b = S2[i]-'a';
		if((check[a]==-1&&check[b]!=-1)||(check[a]!=-1&&check[b]==-1)) NO();
		if(check[a]==-1&&check[b]==-1) {
			check[a]=b,check[b]=a;
			if(a!=b) ans.pb(mp(a,b));
			continue;
		}
		if(check[a]!=b||check[b]!=a) NO();
	}
	printf("%d\n",ans.size());
	FOR(i,ans.size()){
		printf("%c %c\n",ans[i].first+'a',ans[i].second+'a');
	}
	return 0;
}
