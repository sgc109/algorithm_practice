#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N,K;
vector<int> d[1000000];
int A[1000003];
vector<int> init(int l, int r, int node){
	if(l == r) return d[node] = vector<int>(1,A[l]);
	int m = (l+r)/2;
	
	vector<int> L = init(l,m,2*node);
	vector<int> R = init(m+1,r,2*node+1);

	int pos1 = 0 , pos2 = 0;
	vector<int> ret;
	while(pos1 < L.size() && pos2 < R.size()) {
		if(L[pos1] < R[pos2]) ret.push_back(L[pos1++]);
		else ret.push_back(R[pos2++]);
	}
	while(pos1 < L.size()) ret.push_back(L[pos1++]);
	while(pos2 < R.size()) ret.push_back(R[pos2++]);

	return d[node] = ret;
}

int query(int l, int r, int nl, int nr, int node, int k){
	if(l <= nl && nr <= r) return upper_bound(d[node].begin(), d[node].end(), k) - d[node].begin();
	if(nr < l || r < nl) return 0;
	int nm = (nl+nr)/2;
	return query(l,r,nl,nm,2*node,k) + query(l,r,nm+1,nr,2*node+1,k);
}

int main() {
	scanf("%d%d",&N,&K);
	for(int i = 0 ; i < N; i++) scanf("%d",&A[i]);
	init(0,N-1,1);
	long long sum = 0;
	for(int i = 0 ; i < N - K + 1 ; i++){
		int lo = 0, hi = 1<<17;
		while(lo<hi){
			int mid = (lo+hi)/2;
			if(query(i,i+K-1,0,N-1,1,mid) >= (K+1)/2) hi = mid;
			else lo = mid+1;
		}
		sum += lo;
	}

	printf("%lld",sum);
	return 0;
}
