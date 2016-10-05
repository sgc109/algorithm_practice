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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;


char S[300];
int n;
int inParen;
int cnt;
int ansA;
int ansB;

bool isAlpha(char c){
	if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) return true;
	else return false;
}
int main() {
	inp1(n);
	scanf("%s",S);
	FOR(i,n){
		if(isAlpha(S[i])) ++cnt;
		else{
			if(cnt){
				if(inParen){
					++ansB;
				}
				else {
					ansA = max(ansA,cnt);
				}
			}
			if(S[i] == '(') inParen=1;
			else if(S[i] == ')') inParen=0;
			cnt=0;
		}
	}
	if(cnt){
		ansA = max(ansA,cnt);
	}

	printf("%d %d",ansA,ansB);

	return 0;
}