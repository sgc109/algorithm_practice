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

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

void NO(){
	printf("NO");
	exit(0);
}
int n;
char buf[10000];
int pos;
int main() {
	inp1(n);
	FOR(i,n){
		int dist;
		inp1(dist);
		scanf("%s",buf);
		if(buf[0]=='N'){
			if(pos<dist) NO();
			pos-=dist;
		}
		else if(buf[0]=='S'){
			if(pos+dist>20000) NO();
			pos+=dist;
		}
		else if(buf[0]=='E'){
			if(pos==0||pos==20000) NO();
		}
		else {
			if(pos==0||pos==20000) NO();
		}
	}
	if(pos==0) printf("YES");
	else printf("NO");
	return 0;
}
