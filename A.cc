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

int posG,posT;
int n,k;
void NO(){
	printf("NO");
	exit(0);
}
int main() {
	string str;
	inp2(n,k);
	cin >> str;
	FOR(i,n) {
		if(str[i]=='G') posG=i;
		if(str[i]=='T') posT=i;
	}
	if(posG>posT) {
		reverse(str.begin(),str.end());
		posG=n-posG-1;
		posT=n-posT-1;
	}
	while(posG<posT){
		if(str[posG]=='#') NO();
		posG+=k;	
	}
	if(posG==posT) printf("YES");
	else printf("NO");
	return 0;
}