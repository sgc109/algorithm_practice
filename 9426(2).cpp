#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int t[262145];
int A[250003];
int N,K;
int ans;

void update(int pos, int v){
	t[pos += (1<<16)] += v;
	for(;pos>1; pos/=2) t[pos/2] = t[pos] + t[pos^1];
}
int search(int k){
	int pos = 1;
	while(pos < (1<<16)){
		if(k <= t[2*pos]) pos*=2;
		else k-=t[2*pos], pos=2*pos+1;
	}
	return pos-(1<<16);
}

int main() {
	scanf("%d%d",&N,&K);
	for(int i = 0 ; i < N; i++) scanf("%d",&A[i]);
	for(int i = 0 ; i < K; i++) update(A[i],1);
	long long sum = 0;
	for(int i = K; i <= N; i++){
		sum += search((K+1)/2);
		if(i==N) break;
		update(A[i],1);
		update(A[i-K],-1);
	}
	printf("%lld",sum);
	return 0;
}
