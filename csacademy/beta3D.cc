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
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int n;
string str;

void Awin(){
	printf("A");
	exit(0);
}

void Bwin(){
	printf("B");
	exit(0);
}

vi remove0(vi v){
	vi ret;
	FOR(i,v.size()){
		if(v[i]>0) ret.pb(v[i]);
	}
	return ret;
}

void battle(vi v, int turn){
	if(v.size()==0) {
		if(turn) Awin();
		else Bwin();
	}

	int maxV=-1;
	int maxI;
	int minV=INF;
	int minI;
	int cntUp2=0;
	FOR(i,v.size()){
		if(maxV<v[i]){
			maxV=v[i];
			maxI=i;
		}
		if(minV>v[i]){
			minV=v[i];
			minI=i;
		}
		if(v[i]>=2) cntUp2++;
	}
	if(v.size()%2==0){
		if(cntUp2%2==0){
			if(maxV<=2) {
				v[maxI]--;
				battle(remove0(v),turn^1);
			}
			else {
				v[maxI]=2;
				battle(v,turn^1);
			}
		}
		else {
			v[maxI]=1;
			battle(v,turn^1);
		}
	}
	else {
		if(cntUp2%2==0){
			v[maxI]=0;
			battle(remove0(v),turn^1);
		}
		else {
			v[maxI]=0;
			battle(remove0(v),turn^1);
		}
	}
}

int main() {
	inp1(n);
	cin >> str;
	int cntA=0;
	int len=0;
	vi Bs;
	FOR(i,str.size()){
		if(str[i]=='B') ++len;
		if(str[i]=='A'){
			if(len>0) {
				Bs.pb(len);
				len=0;
			}
			++cntA;
		}
	}
	if(cntA%2==0) {
		printf("-1");
		return 0;
	}
	battle(Bs,0);
	return 0;
}