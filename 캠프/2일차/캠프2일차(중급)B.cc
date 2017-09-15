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
#include <map>
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

map<pll,int> dist;
int A,B,C,D;
int main() {
	inp4(A,B,C,D);
	queue<pll> q;
	dist[{C,D}]=1;
	q.push({C,D});
	while(!q.empty()&&dist[{A,B}]==0){
		ll hereA = q.front().first;
		ll hereB = q.front().second;
		q.pop();
		if(dist[{hereA-1,hereB-1}]==0 && hereA-1>=A && hereB-1>=B) dist[{hereA-1,hereB-1}]=dist[{hereA,hereB}]+1,q.push({hereA-1,hereB-1});
		if(hereA%2==0 && hereB%2==0 && dist[{hereA/2,hereB/2}]==0 && hereA/2>=A && hereB/2>=B) dist[{hereA/2,hereB/2}]=dist[{hereA,hereB}]+1,q.push({hereA/2,hereB/2});
	}
	printf("%d",dist[{A,B}]-1);
	return 0;
}
