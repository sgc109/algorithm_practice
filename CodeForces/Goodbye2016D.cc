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

int map[2][320][320][8];
int colored[320][320];
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};

int main() {
	int n;
	inp1(n);
	map[0][160][160][0]=1;
	FOR(i,n){
		int len;
		inp1(len);
		FOR(y,320){
			FOR(x,320){
				FOR(k,8){
					if(!map[i%2][y][x][k]) continue;
					map[i%2][y][x][k]=0;
					int ny=y, nx=x;
					FOR(l,len){
						ny+=dy[k],nx+=dx[k];
						colored[ny][nx]=1;
					}
					map[i%2^1][ny][nx][(k-1+8)%8]=1;
					map[i%2^1][ny][nx][(k+1)%8]=1;
				}
			}
		}
	}
	int ans=0;
	FOR(i,320){
		FOR(j,320){
			ans+=colored[i][j];
		}
	}
	printf("%d",ans);
	return 0;
}
