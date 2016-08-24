#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

priority_queue<int> pqLeft;
priority_queue<int> pqRight;

int mid;

int main() {
	int n;
	scanf("%d",&n);
	FOR(i,n) {
		int num;
		scanf("%d",&num);
		if(i==0) {
			mid = num;
			printf("%d\n",mid);
			continue;
		}

		if(num < mid) {
			if(pqLeft.size() == pqRight.size()) {
				pqRight.push(-mid);
				pqLeft.push(num);
				mid = pqLeft.top();
				pqLeft.pop();
			}
			else pqLeft.push(num);
		}
		else if(num == mid) {
			if(pqLeft.size() == pqRight.size()) pqRight.push(-num);
			else pqLeft.push(num);
		}
		else {
			if(pqLeft.size() == pqRight.size()) pqRight.push(-num);
			else {
				pqLeft.push(mid);
				pqRight.push(-num);
				mid = -pqRight.top();
				pqRight.pop();
			}
		}

		printf("%d\n",mid);
	}

	return 0;
}