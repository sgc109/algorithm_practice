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

string canTransform(string from, string to){
	int pos = 0;
	FOR(i,to.size()){
		if(pos==from.size()) break;
		if(to[i]==from[pos]) ++pos;
		else if(to[i]!='z') return "No";
	}
	if(pos==from.size()) return "Yes";
	return "No";
}

int furthest(int n, int broke){
	int sum=0;
	int i;
	for(i = 1;; ++i){
		sum += i;
		if(sum >= broke) break;
	}
	if(sum==broke && i<=n) return n*(n+1)/2-1;
	return n*(n+1)/2;
}

string isColorable(vector<string> vs){
	int c = vs[0].size();
	int r = vs.size();
	REP(i,1,r){
		REP(j,1,c){
			int same=(vs[i-1][j-1]==vs[i][j-1]);
			if(same && vs[i-1][j]!=vs[i][j]) return "No";
			else if(!same && vs[i-1][j]==vs[i][j]) return "No";
		}
	}
	return "Yes";
}
int main() {
	cout << furthest(3,3);
	return 0;
}