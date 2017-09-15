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
const int MAX_N = 1000000;
const int MOD = 1e9+7;

long long n;

struct Matrix{
	long long num[2][2];
	bool operator==(const Matrix &matrix) const {
		FOR(i,2){
			FOR(j,2){
				if(this->num[i][j]!=matrix.num[i][j]) return false;
			}
		}
		return true;
	}
	Matrix operator*(const Matrix &matrix) const {
		Matrix ret;
		ret.num[0][0] = (this->num[0][0]*matrix.num[0][0]+this->num[0][1]*matrix.num[1][0])%MOD;
		ret.num[0][1] = (this->num[0][0]*matrix.num[0][1]+this->num[0][1]*matrix.num[1][1])%MOD;
		ret.num[1][0] = (this->num[1][0]*matrix.num[0][0]+this->num[1][1]*matrix.num[1][0])%MOD;
		ret.num[1][1] = (this->num[1][0]*matrix.num[0][1]+this->num[1][1]*matrix.num[1][1])%MOD;
		return ret;
	}
};

Matrix powerN(Matrix& matrix, long long n) {
	if(n==0) return Matrix({1,0,0,1});
	if(n%2==1) return matrix*powerN(matrix,n-1);
	Matrix tmp = powerN(matrix,n/2);
	return tmp*tmp;
}

int main() {
	scanf("%lld",&n);
	Matrix base = Matrix({1,1,1,0});
	Matrix matrix = powerN(base,n);
	printf("%d",matrix.num[1][0]);
	return 0;
}