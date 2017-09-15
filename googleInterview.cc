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

struct Bst{
public:
	vector<Bst *> childs;
	int val;
	Bst(int value) : val(value){}
};

int solve(Bst *cur, int l, int r){
	int ret=(l<=cur->val&&cur->val<=r?cur->val:0);
	if(cur->childs.size()==0) return ret;
	if(cur->val < r) ret+=solve(cur->childs[1],l,r);
	if(cur->val > l) ret+=solve(cur->childs[0],l,r);
	return ret;
}

Bst *nodes[MAX_N];

int main() {
	int n;
	inp1(n);
	FOR(i,n) {
		int a;
		inp1(a);
		nodes[i]=new Bst(a);
	}
	FOR(i,n-1){
		int a,b;
		inp2(a,b);
		nodes[a]->childs.push_back(nodes[b]);
	}

	cout << solve(nodes[0],6,12);
	return 0;
}