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

char map[3072][6144];
int main() {
	memset(map,0x20,sizeof(map));
	int n;
	inp1(n);
	int N=n;
	N/=3;
	int limit=0;
	for(N,limit;N;N/=2,limit++){}
	limit--;	
	map[0][0]=map[0][1]=map[0][2]=map[0][3]=map[0][4]=map[1][1]=map[1][3]=map[2][2]='*';
	for(int k = 0, h = 3; k < limit; k++,h<<=1) FOR(i,h) FOR(j,2*h) map[i][j+2*h]=map[i+h][j+h]=map[i][j]; 
	for(int i = n-1; i>=0; i--){
		map[i][2*n-1] = 0;
		printf("%s\n",map[i]);
	}
	
	return 0;
}
