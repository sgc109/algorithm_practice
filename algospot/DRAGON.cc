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
#include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
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
const int MAX_N = 52;

int n,p,l;
ll genFrom[MAX_N];
map<char,string> m;

char solve(int g, int k, char c){
	if(g==n) return m[c][k];
	string str = m[c];
	FOR(i,str.size()){
		if(str[i]!='X'&&str[i]!='Y') {
			if(1<=k) k--;
			else return str[i];
		}
		else{
			if(genFrom[n-g]<=k) k-=genFrom[n-g];
			else return solve(g+1,k,str[i]);
		}		
	}
	return 'f';
}
int main() {
	genFrom[0] = 1;
	FOR(i,MAX_N-1){
		genFrom[i+1] = min(1000000010LL,genFrom[i] + 3*((ll)1<<i));
	}
	m['X']="X+YF";
	m['Y']="FX-Y";
	m['S']="FX";
	int T;
	inp1(T);
	while(T--){
		inp3(n,p,l);
		FOR(i,l){
			printf("%c",solve(0,p+i-1,'S'));
		}
		printf("\n");
	}
	return 0;
}