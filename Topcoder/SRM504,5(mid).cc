// #include <bits/stdc++.h>
// #include <iostream>
#include <unordered_set>
#include <unordered_map>
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

pii dist[10];
int solve(int N) {
	FOR(i,10) dist[i]={-1,-1};
	queue<pii> q;
	q.push({0,0});
	while(!q.empty()){
		int hereNum = q.front().first;
		int hereD = q.front().second;
		q.pop();
		string s="47";
		for(auto c : s){
			int nextNum = hereNum + c-'0';
			int nextD = hereD+1;
			if(dist[nextNum%10].second!=-1) continue;
			dist[nextNum%10] = {nextNum, nextD};
			q.push({nextNum,nextD});
		}
	}
	if(dist[N%10].first > N) return -1;
	else return dist[N%10].second;
}


class TheNumbersWithLuckyLastDigit{
public:
	int find(int n) {
		return solve(n);
	}
}