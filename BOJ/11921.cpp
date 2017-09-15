#include <iostream>
#include <stdio.h>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

static char buffer[8192*64*4];
static int current = 0;

static inline int _read() {
	if(current == 8192*64*4) {
		fread(buffer,1,8192*64*4,stdin);
		current = 0;
	}
	return buffer[current++];
}

static int x,c;

static inline int _readInput() {
	x = 0;
	c = _read();
	while(c <= 32) c = _read();
	while(c > 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}

	return x;
}

int main() {
	int n;
	long long sum = 0;
	scanf("%d",&n);
	FOR(i,n) {
		sum += _readInput();
	}
	printf("%d\n%lld",n,sum);

	return 0;
}