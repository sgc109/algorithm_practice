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
#include <unordered_set>
#include <set>
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

typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;

const int INF = 0x3a3a3a3a;
const long long INFL = 0x3a3a3a3a3a3a3a3a;
const int MAX_N = 1000000;

int cnt[262144];
multiset<int> ms[262144];
int n;
char in[30];
int main() {
	inp1(n);
	getchar();
	FOR(i,n){
		gets(in);
		int len = strlen(in);
		int num=0;
		int pos=0;
		REP(i,2,len) {
			if((in[i]-'0')%2==0) {
				pos*=2;
			}
			else {
				pos*=2;
				pos+=1;
			}
			num*=10;
			num+=in[i]-'0';
		}

		// printf("pos:%d, num:%d\n",pos,num);
		if(in[0] == '+') {
			ms[pos].insert(num);
			++cnt[pos];
		}
		else if(in[0] == '-') {
			ms[pos].erase(ms[pos].find(num));
			--cnt[pos];
		}
		else if(in[0] == '?') {
			printf("%d\n",cnt[pos]);
		}
	}
	
	return 0;
}