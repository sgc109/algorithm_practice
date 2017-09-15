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

int T,N;
int check[30];
int ansCnt;
string ansName;
char buf[100];
vector<string> vs;
int main() {
	freopen("output.txt","w",stdout);
	scanf("%d ",&T);
	REP(t,1,T){
		vs.clear();
		ansCnt=0;
		scanf("%d ",&N);
		FOR(i,N){
			gets(buf);
			vs.push_back(string(buf));
		}
		sort(all(vs));
		for(auto str : vs){
			int cnt=0;
			memset(check,0,sizeof(check));
			for(char c : str){
				if(check[c-'A']) continue;
				check[c-'A']=1,cnt++;
			}
			if(ansCnt<cnt) ansCnt=cnt,ansName=str;
		}
		printf("Case #%d: ",t);
		printf("%s\n",ansName.c_str());
	}
	return 0;
}
