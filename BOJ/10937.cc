// #include <bits/stdc++.h>
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
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, pair<int, int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0) * 2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int score[300][300], dp[130][1 << 11];
char pane[13][13];
int N;
int go(int pos, int state) {
	state &= ((1 << N) - 1);
	if (pos == N*N) return 0;
	int& ret = dp[pos][state];
	if (ret != -1) return ret;
	int y = pos/N, x = pos%N;
	ret = 0;
	if (x<N-1) ret = max(ret, score[pane[y][x]][pane[y][x + 1]] + go(pos + 2, (state << 2) | 3));
	if (y>0 && (state&(1 << (N - 1))) == 0) ret = max(ret, score[pane[y - 1][x]][pane[y][x]] + go(pos + 1, (state << 1) | 1));
	ret = max(ret, go(pos + 1, state << 1));
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int arr[] = { 100,70,40,0,70,50,30,0,40,30,20,0,0,0,0,0 };
	char alpha[5] = "ABCF";
	int cnt = 0;
	FOR(i, 4) FOR(j, 4) score[alpha[i]][alpha[j]] = arr[cnt++];
	inp1(N);
	FOR(i, N) scanf("%s", pane[i]);
	printf("%d", go(0, (1 << N) - 1));
	return 0;
}
