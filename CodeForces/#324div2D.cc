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
const int MAX_N = 40002;

int notPrime[MAX_N];

bool isPrime(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}
int main() {

	for(int i=2; i*i<=MAX_N-2; i++){
		if(notPrime[i]) continue;
		for(int j=i*2; j<=MAX_N-2; j+=i){
			notPrime[j]=1;
		}
	}
	notPrime[0]=notPrime[1]=1;
	
	int n;
	inp1(n);
	
	if(isPrime(n)){
		printf("1\n%d",n);
		return 0;
	}
	int prime;
	for(prime=n-2; prime>=0; prime-=2){
		if(isPrime(prime)) break;
	}
	if(!notPrime[n-prime]) {
		printf("2\n%d %d",n-prime,prime);
	}
	for(int i=2; i<=n-prime;i++){
		if(!notPrime[i]&&!notPrime[n-prime-i]){
			printf("3\n%d %d %d",i,n-prime-i,prime);
			return 0;
		}
	}
	return 0;
}