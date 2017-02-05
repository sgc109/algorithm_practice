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
#define all(v) (v).begin(),(v).end()
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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

char map[5][5];
int cntWho(char c){
	int ret=0;
	FOR(i,4){
		int cnt=0;
		FOR(j,4){
			if(map[i][j]==c) cnt++;
		}
		if(cnt>=3&&map[i][1]==c&&map[i][2]==c) ret++;
	}
	FOR(i,4){
		int cnt=0;
		FOR(j,4){
			if(map[j][i]==c) cnt++;
		}
		if(cnt>=3&&map[1][i]==c&&map[2][i]==c) ret++;
	}
	int cnt=0;      
	FOR(i,4){
		if(map[i][i]==c) cnt++;
	}
	if(cnt>=3&&map[1][1]==c&&map[2][2]==c) ret++;

	cnt=0;
	FOR(i,4){
		if(map[i][3-i]==c) cnt++;
	}
	if(cnt>=3&&map[1][2]==c&&map[2][1]==c) ret++;
	
	cnt=0;
	FOR(i,3) if(map[i+1][i]==c) cnt++;
	if(cnt==3) ret++;
	cnt=0;
	FOR(i,3) if(map[i][i+1]==c) cnt++;
	if(cnt==3) ret++;
	cnt=0;
	FOR(i,3) if(map[i][2-i]==c) cnt++;
	if(cnt==3) ret++;
	cnt=0;
	FOR(i,3) if(map[i+1][3-i]==c) cnt++;
	if(cnt==3) ret++;

	return ret;
}
void YES(){
	printf("YES");
	exit(0);
}
int main() {
	FOR(i,4){
		scanf("%s",map[i]);
	}
	FOR(i,4){
		FOR(j,4){
			if(map[i][j]!='.') continue;
			map[i][j]='x';
			int ret = cntWho('x');
			if(ret>0) YES();
			map[i][j]='.';
		}
	}	
	printf("NO");
	return 0;
}
