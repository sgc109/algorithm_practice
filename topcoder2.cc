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


int cnt[26];
int maxCnt=-1;
int getmin1(string str){
	FOR(i,str.size()){
		cnt[str[i]-'a']++;
		maxCnt = max(maxCnt, cnt[str[i]-'a']);
	}
	return str.size()-maxCnt;
}

int solve(int pos, string str){
	if(pos==str.size()) return 0;
	if(pos==str.size()-1) return 0;
	if(str[pos]==str[pos+1]) return 1+solve(pos+2,str);
	return solve(pos+1,str);
}
vi chunk;
int getmin(string s){
	return 1+min(solve(0,s.substr(s.size()-1)),solve(1,s));
}
int main() {
	printf("%d",getmin("LRRR"));
	return 0;
}