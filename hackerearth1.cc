// #include <bits/stdc++.h>
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
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int left[100003];
int T,N;
int A[100003];
ll pSum[100003];
int main() {
	inp1(T);
	while(T--){
		memset(left,0,sizeof(left));
		memset(pSum,0,sizeof(pSum));
		inp1(N);
		FOR(i,N) inp1(A[i]),pSum[i+1]=pSum[i]+A[i];
		int l=0,r=INF;
		REP(i,1,N){
			int updL=-1;
			int mod = pSum[i]%N;
			if(mod) {
				if(left[mod]) updL = left[mod];
			}
			else updL = left[mod];
			if(updL != -1 && r-l > i-updL) l = updL, r = i;
			left[mod]=i;
		}
		printf("%d %d\n",l+1,r);
	}

	return 0;
}
