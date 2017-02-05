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

char alpha[16];
int L,C;
int vowCnt;
int conCnt;
vector<string> ans;
void solve(int pos, string& code){
	if(code.size()==L) {
		if(vowCnt>=1&&conCnt>=2) ans.pb(code);
		return;
	}
	if(pos==C) return;
	solve(pos+1,code);
	code+=alpha[pos];
	if(alpha[pos]=='a'||alpha[pos]=='e'||alpha[pos]=='i'||alpha[pos]=='o'||alpha[pos]=='u') vowCnt++;
	else conCnt++;
	solve(pos+1,code);
	if(alpha[pos]=='a'||alpha[pos]=='e'||alpha[pos]=='i'||alpha[pos]=='o'||alpha[pos]=='u') vowCnt--;
	else conCnt--;
	code.pop_back();
}
int main() {
	inp2(L,C);
	FOR(i,C) scanf(" %c",alpha+i);
	sort(alpha,alpha+C);
	string S;
	solve(0,S);
	sort(ans.begin(),ans.end());
	FOR(i,ans.size()) printf("%s\n",ans[i].c_str());
	return 0;
}
