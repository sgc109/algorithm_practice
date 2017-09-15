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

char map[6561][6562];
int main() {
	int n;
	inp1(n);
	int limit=0;
	int N;
	for(limit, N=n; N; N/=3, limit++){}
	limit--;
	map[0][0] = '*';
	for(int k = 0, size = 1; k < limit; k++,size*=3){
		FOR(i,size){
			FOR(j,size){
				map[i][j+size]=map[i][j+2*size]=map[i+size][j]=map[i+size][j+2*size]=map[i+2*size][j]=map[i+2*size][j+size]=map[i+2*size][j+2*size]=map[i][j];
				map[i+size][j+size] = ' ';
			}
		}
	}
	FOR(i,n){
		map[i][n]=0;
		printf("%s\n",map[i]);
	}
	return 0;
}
