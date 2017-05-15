#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int t[250003];
int A[250003];
int N,K;
void update(int pos, int v){
	while(pos < (1<<16)){
		t[pos] += v;
		pos += pos&-pos;
	}
}
int search(int k){
    int idx=0;
    for(int i=16;i>=0;i--){
        if(idx+(1<<i)<=(1<<16)-1 && t[idx+(1<<i)] <k){
            k-=t[idx+(1<<i)];
            idx=idx+(1<<i);
        }
    }
    if(!k) return idx;
    return idx+1;
}
int main() {
	scanf("%d%d",&N,&K);
	for(int i = 0 ; i < N; i++) scanf("%d",&A[i]);
	for(int i = 0 ; i < K; i++) update(A[i]+1,1);
	long long sum = 0;

	for(int i = K; i <= N; i++){
		sum += search((K+1)/2)-1;
		if(i==N) break;
		update(A[i]+1,1);
		update(A[i-K]+1,-1);
	}
	printf("%lld",sum);
	return 0;
}
