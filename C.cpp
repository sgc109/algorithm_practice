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
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;

const int INF = 0x3a3a3a3a;
const int MAX_N = 1000000;

char S[100005];

int main() {
	gets(S);

	int left=-1, right=-1;
	FOR(i,strlen(S)) {
		if(S[i] != 'a') {
			left = i;
			putchar(S[i]-1);
			break;
		}
		
		if(i == (strlen(S)-1)) {
			putchar('z');
			return 0;
		}
		else putchar(S[i]);
	}
	right = left;	
	REP(i,left+1,strlen(S)) {
		if(S[i] == 'a') break;
		right = i;
		putchar(S[i]-1);
	}
	REP(i,right+1,strlen(S)) {
		putchar(S[i]);
	}

	return 0;
}