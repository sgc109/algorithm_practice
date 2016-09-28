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

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1000000;

int h[4][100];
char s1[50],s2[100];
int len1,len2;
int k;

int match[26];
int length[26];

int solve(int pos1, int pos2){
	if(pos1>=len1 && pos2>=len2) return 1;
	if(pos2>=len2) return 0;
	if(pos1>=len1) return 0;
	int ret = 0;
	for(int i = 1; i <= k; ++i){
		if(match[s1[pos1]-'a'] == -1) {
			match[s1[pos1]-'a'] = h[i][pos2];
			length[s1[pos1]-'a'] = i;
			ret |= solve(pos1+1,pos2+i);
			match[s1[pos1]-'a'] = -1;
			length[s1[pos1]-'a'] = -1;
		}
		else{
			if(match[s1[pos1]-'a'] != h[i][pos2]) continue;
			ret |= solve(pos1+1,pos2+length[s1[pos1]-'a']);
		}
	}
	return ret;
}
int main() {
	int T;
	inp1(T);
	while(T--){
		memset(match,-1,sizeof(match));
		memset(h,0,sizeof(h));
		memset(length,-1,sizeof(length));
		inp1(k);
		scanf("%s %s",s1,s2);
		len1=strlen(s1);
		len2=strlen(s2);

		FOR(i,len2){
			int tmp=s2[i];
			for(int j = i; j<(len2<=i+k?len2:i+k); ++j){
				h[j-i+1][i]=tmp;
				tmp=tmp*512+s2[j+1];
			}
		}

		printf("%d\n",solve(0,0));
	}
	return 0;
}