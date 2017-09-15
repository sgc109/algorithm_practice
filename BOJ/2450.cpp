#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
int A[100003];
int totCnt[4];
int cnt[4][4];

int main() {
	cin >> N;
	int a[3] = {1,2,3};
	for(int i = 0 ; i < N ; i++) cin >> A[i], totCnt[A[i]]++;

	int ans = inf;
	do{
		int cntSwap = 0;
		memset(cnt,0,sizeof(cnt));
		int prev = 0;
		int limit = totCnt[a[0]];
		for(int i = 0 ; i < 3; i++){
			for(int j = prev ; j < limit; j++){
				for(int k = 0 ; k < 3; k++) if(A[j] == a[k]) cnt[i][k]++;
			}
			prev = limit;
			if(i < 2) limit += totCnt[a[i+1]];
		}

		int c = min(cnt[0][1], cnt[1][0]);
		cntSwap += c;
		cnt[0][1] -= c, cnt[1][0] -= c;
		cnt[0][0] += c, cnt[1][1] += c;
		
		c = min(cnt[0][2], cnt[2][0]);
		cntSwap += c;
		cnt[0][2] -= c, cnt[2][0] -= c;
		cnt[0][0] += c, cnt[2][2] += c;

		c = min(cnt[0][2], cnt[1][0]);
		cntSwap += c;
		cnt[0][2] -= c, cnt[1][0] -= c;
		cnt[0][0] += c, cnt[1][2] += c;

		c = min(cnt[0][1], cnt[2][0]);
		cntSwap += c;
		cnt[0][1] -= c, cnt[2][0] -= c;
		cnt[0][0] += c, cnt[2][1] += c;

		cntSwap += cnt[1][2];

		ans = min(ans, cntSwap);
		
	} while(next_permutation(a,a+3));

	cout << ans;
	return 0;
}
