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

vi node;
int n;
int size;

void build(vi& v){
	FOR(i,size) node[size+i] = v[i];
	for(int i = size-1; i >=1; i--) node[i] = max(node[i<<1],node[i<<1|1]);
}

int query(int l, int r){
	int ret = -INF;
	l+=size;
	r+=size;
	while(l<=r){
		ret = max(ret, max(node[l],node[r]));
		l++;l>>=1;
		r--;r>>=1;
	}
	return ret;
}

void update(int pos, int val){
	pos+=size;
	node[pos]=val;
	while(pos>1){
		node[pos>>1]=max(node[pos],node[pos^1]);
		pos>>=1;
	}
}

int main() {
	inp1(n);
	size = 1<<((int)ceil(log2(n)));
	vi v(size,0);
	FOR(i,n) inp1(v[i]);
	node.resize(2*size);
	build(v);
	update(1,10);
	cout << query(0,3);
	return 0;
}