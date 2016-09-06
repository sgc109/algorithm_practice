#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <string.h>
#include <stdlib.h>
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
const int MAX_V = 1000000;

bool isAlpha(int c) {
	if(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) return true;
	return false;
}

int change(int c) {
	if('A' <= c && c <= 'Z') {
		c += 13;
		if(c > 'Z') c -= 26;
	}
	else{
		c += 13;
		if(c > 'z') c -= 26;
	}
	return c;
}

int main() {
	char s[200];
	gets(s);
	int len = strlen(s);
	FOR(i,len) {
		if(isAlpha(s[i])) printf("%c",change(s[i]));
		else printf("%c",s[i]);
	}
	return 0;
}