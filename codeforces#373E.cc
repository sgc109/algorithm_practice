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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 100002;
const int MOD = 1e9+7;

int rangeFiboSum[4*MAX_N];
int lazy[4*MAX_N];
int arr[MAX_N];
int size;
int n,m;

struct Matrix{
	long long num[2][2];
	Matrix operator*(const Matrix &matrix) const {
		Matrix ret;
		ret.num[0][0] = (this->num[0][0]*matrix.num[0][0]+this->num[0][1]*matrix.num[1][0])%MOD;
		ret.num[0][1] = (this->num[0][0]*matrix.num[0][1]+this->num[0][1]*matrix.num[1][1])%MOD;
		ret.num[1][0] = (this->num[1][0]*matrix.num[0][0]+this->num[1][1]*matrix.num[1][0])%MOD;
		ret.num[1][1] = (this->num[1][0]*matrix.num[0][1]+this->num[1][1]*matrix.num[1][1])%MOD;
		return ret;
	}
};

Matrix powerN(Matrix &matrix, int n){
	if(n==0) return Matrix({1,0,0,1});
	if(n%2==1) return matrix*powerN(matrix,n-1);
	Matrix ret = powerN(matrix,n/2);
	return ret*ret;
}

int fibo(int n){
	Matrix base = Matrix({1,1,1,0});
	Matrix f = powerN(base,n);
	return (int)f.num[0][1];
}

void init(int nodeLeft, int nodeRight, int node) {
	if(nodeLeft==nodeRight){rangeFiboSum[node]=fibo(arr[nodeLeft]);return;}
	int nodeMid=(nodeLeft+nodeRight)>>1;
	init(nodeLeft,nodeMid,2*node);
	init(nodeMid+1,nodeRight,2*node+1);
	rangeFiboSum[node]=(rangeFiboSum[2*node]+rangeFiboSum[2*node+1])%MOD;
}

void update(int nodeLeft, int nodeRight, int left, int right, int node, int val) {
	if(lazy[node]!=0) {

	}

	if(left<=nodeLeft&&nodeRight<=right) {

	}
}

int query(int nodeLeft, int nodeRight, int left, int right, int node){
	
}

int query(int left, int right){
	return query(0,size-1,left,right,1);
}
int main() {
	inp2(n,m);
	FOR(i,n) inp1(arr[i]);
	size=n;
	init(0,size-1,1);
	FOR(i,m){
		int c,l,r,x;
		inp3(c,l,r);
		if(c==1) {
			inp1(x);

		}
		else {
			printf("%d\n",query(l,r));
		}
	}
	return 0;
}