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
const int MAX_N = 200000000;

int notPrime[MAX_N+2];
int main() {
	for(int i = 2; i*i <= MAX_N; i++){
		if(notPrime[i]) continue;
		for(int j = 2*i; j <= MAX_N; j+=i){
			notPrime[j]=1;
		}
	}
	while(1){
		int n;
		inp1(n);
		if(!n) break;
		bool notFound=true;
		for(int i=3; i<=n/2+1; i+=2){
			if(!notPrime[i]&&!notPrime[n-i]) {
				printf("%d = %d + %d\n",n,i,n-i);
				notFound=false;
				break;
			}
		}
		if(notFound) printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}