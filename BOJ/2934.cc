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

int t[100002];
int size;
int query(int pos){
	int ret=0;
	while(pos) {
		ret+=t[pos];
		pos-=pos&-pos;
	}
	return ret;
}
void add(int pos, int val){
	while(pos<=size){
		t[pos]+=val;
		pos+=pos&-pos;
	}
}
int main() {
	size=100000;
	int n;
	inp1(n);
	FOR(i,n){
		int l,r;
		inp2(l,r);
		int ql = query(l); int qr = query(r);
		printf("%d\n",ql+qr);
		add(l,-ql); add(l+1,ql);
		add(r,-qr); add(r+1,qr);
		--r;++l;
		if(r<l) continue;
		add(l,1); add(r+1,-1);
	}
	return 0;
}