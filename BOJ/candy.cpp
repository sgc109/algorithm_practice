#include <stdio.h>
#include <iostream>
#include <vector>
#define REP(i,a,b) for(int i = a; i < b; ++i) 
#define FOR(i,n) REP(i,0,n)

using namespace std;


struct SegTree{
	vector<int> rangeSum;
	int size;
	SegTree(vector<int> &v) {
		size = v.size();
		rangeSum.resize(4*size);
	}

};

vector<int> candies;
int n;

int main() {
	candies = vector<int>(1000000,0);
	SegTree segTree(candies);
	
	scanf("%d",&n);
	FOR(i,n) {
		
	}

	return 0;
}