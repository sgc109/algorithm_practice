// #include <bits/stdc++.h>
#include <unordered_set>
// #include <unordered_map>
// #include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
int divs[100003];
int N,K;
ll dp[13][100003];
ll psum[13];
vector<int> divisors[100003];

int main() {
	for(int i = 1; i <= 100000; i++) divs[i]=i;	
	scanf("%d%d",&N,&K);
	for(int i = 1; i <= K; i++) {
		for(int j = 2*i; j <= K; j+=i){
			divisors[j].push_back(i);
		}
	}
	for(int i=1;i<=K;i++) psum[1]+=dp[1][i]=1;
	for(int i=2;i<=N;i++) {
		for(int j=1;j<=K;j++){
			ll sum=0;
			for(int k : divisors[j]){
				(sum+=dp[i-1][k])%=MOD;
			}
			dp[i][j]=(psum[i-1]-sum+MOD)%MOD;
			(psum[i]+=dp[i][j])%=MOD;
		}
	}
	printf("%lld",psum[N]);
	return 0;
}
