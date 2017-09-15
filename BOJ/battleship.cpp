#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define REP(i,a,b) for(int i = a; i < b; ++i) 
#define FOR(i,n) REP(i,0,n)

using namespace std;

struct Ship{
	int x1,y1,x2,y2;
	int weight;
	int shipNum;
};

bool cmpX(Ship shipA, Ship shipB) {
	return shipA.x1 < shipB.x1;
}

bool cmpY(Ship shipA, Ship shipB) {
	return shipA.y1 < shipB.y1;
}

vector<Ship> v;
vector<bool> defeated;
int T,N,K,L;

struct SegTree{
	vector<Ship> maxArr;
	int size;
	SegTree(vector<Ship> &v) {
		size = v.size();
		maxArr.resize(4*size);
		init(0, size-1, 1, v);
	}
	Ship init(int nodeLeft, int nodeRight, int node, vector<Ship> &v) {
		if(nodeLeft == nodeRight) return maxArr[node] = v[nodeLeft];

		int nodeMid = (nodeLeft + nodeRight) / 2;
		Ship maxLeft = init(nodeLeft, nodeMid, 2*node, v);
		Ship maxRight = init(nodeMid + 1, nodeRight, 2*node+1, v);

		if(maxLeft.weight <= maxRight.weight) return maxArr[node] = maxRight;
		return maxArr[node] = maxLeft;
	}
};

int main() {
	scanf("%d",&T);
	FOR(t,T) {
		scanf("%d%d%d",&N,&K,&L);
		v = vector<Ship>(K);
		defeated = vector<bool>(K);
		
		FOR(i,K) {
			int x1,y1,x2,y2,w;
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&w);
			v[i].x1 = x1;
			v[i].y1 = y1;
			v[i].x2 = x2;
			v[i].y2 = y2;
			v[i].weight = w;
			v[i].shipNum = i;
		}
		sort(v.begin(), v.end(), cmpX);
		SegTree segTreeX(v);
		sort(v.begin(), v.end(), cmpY);
		SegTree segTreeY(v);
	}


	return 0;
}