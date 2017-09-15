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
#include <deque>
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

int cnt[3];
int cnt2[3];
string S;
void NO(){printf("-1");exit(0);}
bool isPoss(int a, int b, int c){
	if(b<=1&&c<=1) return true;
	else if(b<=1&&c>1) return (c-1)*2<=a+b;
	else if(b>1&&c==1) return (b-1)<=a+c;
	return isPoss(a-1,b-1,c-1);
}
string solve(int a, int b, int c){
	string ret;
	if(c>0&&b>1&&a>0) ret+="CBAB"+solve(a-1,b-2,c-1);
	else if(a&&b&&c) ret+="CBA"+solve(a-1,b-1,c-1);
	else if(c>1){
		if(!a) NO();
		ret+="CAA"+solve(a-2,b,c-1);
	}
	else if(b>1){
		if(b-1>a+c) NO();
		if(c) ret+="CB"+solve(a,b-1,c-1);
		else ret+="AB"+solve(a-1,b-1,c);
	}
	else {
		FOR(i,a) ret+="A";
		if(b) ret+="B";
		if(c) ret+="C";
	}

	return ret;
}
int main() {
	cin >> S;
	FOR(i,S.size()) cnt[S[i]-'A']++;
	cout << solve(cnt[0],cnt[1],cnt[2]);
	return 0;
}
