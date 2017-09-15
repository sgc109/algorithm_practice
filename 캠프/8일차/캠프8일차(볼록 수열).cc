// #include <bits/stdc++.h>
// #include <unordered_set>
// #include <unordered_map>
#include <vector>
#include <cstdio>
#include <iostream>
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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)z
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

queue<int> q;
int N;
int A[53];
int inQ[53];
int main() {
	inp1(N);
	FOR(i,N) inp1(A[i]);
	ll ans=0;
	REP(i,1,N-2) if(A[i-1]+A[i+1]<2*A[i]) q.push(i),inQ[i]=1;
	while(!q.empty()){
		int i = q.front();
		q.pop(),inQ[i]=0;
		if(i==0||i==N-1||A[i-1]+A[i+1]>=2*A[i]) continue;
		ans+=A[i]-(A[i-1]+A[i+1])/2;
		A[i]=(A[i-1]+A[i+1])/2;
		if(!inQ[i-1]) inQ[i-1]=1,q.push(i-1);
		if(!inQ[i+1]) inQ[i+1]=1,q.push(i+1);
	}
	printf("%lld",ans);
	return 0;
}
