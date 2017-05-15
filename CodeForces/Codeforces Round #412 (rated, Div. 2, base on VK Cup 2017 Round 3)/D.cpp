#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
typedef long long ll;

ll cntSolved[5];
int N;
int solveTime[2][5];
int calcScore(ll a, ll b){
	for(int i = 1 ; i <= 5; i++){
		if((1<<i)*a > b) return 500*i;
	}
	return 3000;
}
bool possi(ll cntAdd){
	ll scoreA = 0, scoreB = 0;
	for(int i = 0 ; i < 5; i++){
		if(solveTime[1][i] != -1 && solveTime[0][i] > solveTime[1][i]) { // 내가 불리한 상황
			scoreA += (250 - solveTime[0][i]) * calcScore(cntSolved[i]+cntAdd, N+cntAdd) / 250;
			scoreB += (250 - solveTime[1][i]) * calcScore(cntSolved[i]+cntAdd, N+cntAdd) / 250;
		}
		else { // 둘다 각각 못풀었을 수도 있고 
			if(solveTime[0][i] != -1) scoreA += (250 - solveTime[0][i]) * calcScore(cntSolved[i], N+cntAdd) / 250;
			if(solveTime[1][i] != -1) scoreB += (250 - solveTime[1][i]) * calcScore(cntSolved[i], N+cntAdd) / 250;
		}
	}
	return scoreA > scoreB;
}
int main() {
	scanf("%d",&N);
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < 5; j++){
			int a;
			scanf("%d",&a);
			if(i < 2) solveTime[i][j] = a;
			if(a != -1) cntSolved[j]++;
		}
	}

	ll lo = 0, hi = 1e7+1;
	ll i;
	for(i = 0 ; i < 1000000; i++){
		if(possi(i)) break;
	}
	if(i==1000000) printf("-1");
	else printf("%lld",i);
	return 0;
}
