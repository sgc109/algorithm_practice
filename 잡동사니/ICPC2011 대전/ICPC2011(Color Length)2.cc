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

char s1[5005];
char s2[5005];
int len1,len2;
int minPos[26];
int maxPos[26];
int main() {
	int T;
	inp1(T);
	while(T--){
		FOR(i,26) minPos[i]=INF;
		FOR(i,26) maxPos[i]=-INF;
		scanf("%s %s",s1,s2);
		len1=strlen(s1);
		len2=strlen(s2);
		int pos1=0,pos2=0;
		while(pos1<len1&&pos2<len2){
			minPos[s2[pos2]-'A'] = min(minPos[s2[pos2]-'A'], pos1+pos2);
			maxPos[s2[pos2]-'A'] = max(maxPos[s2[pos2]-'A'], pos1+pos2);
			if(s1[pos1]==s2[pos2]) {
				++pos1;
			}
			else {
				++pos2;
			}
		}
		if(pos1==len1){
			while(pos2<len2){
				minPos[s2[pos2]-'A'] = min(minPos[s2[pos2]-'A'], pos1+pos2);
				maxPos[s2[pos2]-'A'] = max(maxPos[s2[pos2]-'A'], pos1+pos2);
				++pos2;
			}
		}
		else if(pos2==len2){
			while(pos1<len1){
				minPos[s1[pos1]-'A'] = min(minPos[s1[pos1]-'A'], pos1+pos2);
				maxPos[s1[pos1]-'A'] = max(maxPos[s1[pos1]-'A'], pos1+pos2);
				++pos1;
			}
		}
		int ans=0;
		FOR(i,26){
			if(minPos[i]==INF) continue;
			ans+=maxPos[i]-minPos[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}