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
const int MAX_N = 100000000;
int divs[MAX_N+2];
int countDivs(int x){
	int ret=1;
	int last=-2,cnt=0;
	for(;x>1;x=x/divs[x]){
		if(last==divs[x]) cnt++;
		else ret*=cnt+1,cnt=1,last=divs[x];
	}
	return ret*(cnt+1);
}
int main() {
	int K=MAX_N;
	for(int i = 1; i <= K; i++) divs[i]=i;	
	for(int i = 2; i*i <= K; i++){
		if(divs[i]!=i) continue;
		for(int j = i*2; j <= K; j+=i){
			divs[j]=min(divs[j],i);
		}
	}
	int ans=0,ans2;
	for(int i = 1; i <= K; i++){
		if(ans<countDivs(i)) ans=countDivs(i),ans2=i;
	}
	printf("%d %d",ans,ans2);

	return 0;
}
