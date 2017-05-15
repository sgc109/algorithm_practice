#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int t[1000003];
int A[1000003];
int N,K;
void update(int pos, int v){
	while(pos < (1<<16)){
		t[pos] += v;
		pos += pos&-pos;
	}
}
int query(int pos){
	int ret = 0;
	while(pos > 0){
		ret += t[pos];
		pos -= pos&-pos;
	}
	return ret;
}

int main() {
	scanf("%d%d",&N,&K);
	for(int i = 0 ; i < N; i++) scanf("%d",&A[i]);
	for(int i = 0 ; i < K; i++) update(A[i]+1,1);
	long long sum = 0;

	for(int i = K; i <= N; i++){
		int lo = 0, hi = 1<<16;
		while(lo<hi){
			int mid = (lo+hi)/2;
			int s = query(mid);
			if(s >= (K+1)/2) hi = mid;
			else lo = mid+1;
		}
		sum += lo-1;
		if(i==N) break;
		update(A[i]+1,1);
		update(A[i-K]+1,-1);
	}
	printf("%lld",sum);
	return 0;
}
