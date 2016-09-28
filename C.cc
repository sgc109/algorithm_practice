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

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 200004;
int n,t;
char S[MAX_N];
int main() {
	FILE *fp = fopen("output.txt","wb");
	inp2(n,t);
	scanf("%s",S);
	int len = strlen(S);
	bool findDot=false;
	int start=-1;
	int dotIndex;
	FOR(i,len) {
		if(S[i]=='.') {
			dotIndex=i;
			findDot=true;
		}
		if(findDot && S[i] >= '5') {
			start = i;
			break;
		}
	}
	if(start == -1) {
		fprintf(fp,"%s",S);
		return 0;
	}
	int pos = start;
	int carry=0;

	while(1) {
		if(S[pos-1] == '.') {
			carry=1;
		}
		else {
			++S[pos-1];
		}
		--pos;
		--t;
		if(t <= 0 || S[pos]=='.' || ('0' <= S[pos] && S[pos] < '5')) break;
	}

	if(S[pos]=='.') S[pos]=0;
	else S[pos+1]=0;
	
	if(carry){
		pos = dotIndex-1;
		while(1){
			if(S[pos] < '9') {
				++S[pos];
				break;
			}
			else {
				S[pos]='0';
			}
			--pos;
			if(pos < 0) {
				fprintf(fp,"1");
				break;
			}
		}
	}	
	fprintf(fp,"%s",S);		
	
	return 0;
}