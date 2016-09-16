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
// #include <unordered_set>
#include <set>
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

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 100000;

long long n,k;

long long maxLen, maxNum;
long long makeNum,sameCnt;
long long useK;
long long a[MAX_N];
int l,r;
int main() {
	scanf("%I64d%I64d",&n,&k);
	FOR(i,n){
		scanf("%I64d",a+i);
	}
	sort(a,a+n);

	makeNum=a[0];
	while(r<n) {
		if(a[r] != makeNum) {
			useK += sameCnt*(a[r]-makeNum);
			makeNum = a[r];
			if(k < useK) {
				while(useK > k) {
					useK -= makeNum-a[l];
					--sameCnt;
					++l;
				}
			}
			++sameCnt;
			if(maxLen<sameCnt) {
				maxLen=sameCnt;
				maxNum=makeNum;
			}
			++r;
		}
		else {
			++sameCnt;
			if(maxLen<sameCnt) {
				maxLen=sameCnt;
				maxNum=makeNum;
			}
			++r;
		}
		// printf("makeNum:%d, sameCnt:%d\n",makeNum,sameCnt);
	}
	printf("%I64d %I64d",maxLen,maxNum);
	return 0;
}