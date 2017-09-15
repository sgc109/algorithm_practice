#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
int A[2000003];
vector<int> S;
int trans(int x){
	return 2*x-1;
}
void manacher(){
	int R = -1, p;
	for(int i = 0 ; i < S.size() ; i++){
		if(R < i) A[i] = 0;
		else A[i] = min(R-i, A[2*p-i]);
		while(i - A[i] - 1 >= 0 && i + A[i] + 1 < S.size() && S[i - A[i] - 1] == S[i + A[i] + 1]) A[i]++;
		if(R < A[i] + i) R = A[i] + i, p = i;
	}
}
int main() {
	scanf("%d",&N);
	S.push_back(0);
	for(int i = 0 ; i < N; i++) {
		int a;
		scanf("%d",&a);
		S.push_back(a);
		S.push_back(0);
	}
	manacher();
	scanf("%d",&M);
	for(int i = 0 ; i < M; i++){
		int s,e;
		scanf("%d%d",&s,&e);
		s = trans(s), e = trans(e);
		if(A[(s+e)/2] >= (e-s)/2) printf("1\n");
		else printf("0\n");
	}
	return 0;
}