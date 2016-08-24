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
#define MAXIMUM_BUFFER_CAPACITY 15000000

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

int a[5000000];

static char _buffer[131072];
static int _currentChar = 0;
static int _charsNumber = 0;
   
static inline int _read() {
    if (_currentChar == 131072) {
        _charsNumber = fread(_buffer, 1, 131072, stdin);
        _currentChar = 0;
    }
    return _buffer[_currentChar++];
}
   
int c, x;
   
static inline int _readInt() {
	bool minus = false;
    c = _read();
    while (c <= 32) c = _read();
    x = 0;
    while (c > 32) {
    	if(c == '-') minus = true;
        else {
        	x *= 10;
        	x += c - '0';
    	}
        c = _read();
    }
    if(minus) x = -x;
    return x;
}

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	FOR(i,n) {
		a[i] = _readInt();
	}
	nth_element(a,a+k-1,a+n);
	printf("%d",a[k-1]);

	return 0;
}