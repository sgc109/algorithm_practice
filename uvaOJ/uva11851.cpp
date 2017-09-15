#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
int price[30];
map<int, int> mp;
int pow3[30];
int sum;
int main() {
	pow3[0] = 1;
	for(int i = 1 ; i < 13; i++) pow3[i] = pow3[i-1]*3;

	while(1){
		mp.clear();
		sum = 0;

		scanf("%d",&N);
		if(!N) break;
		for(int i = 0 ; i < N; i++) scanf("%d", price+i), sum += price[i];

		int ans = sum;
		int L = N/2;
		int R = (N+1)/2;
		for(int i = 0 ; i < pow3[L]; i++) {
			int A = 0, B = 0;
			for(int j = i, k = 0;j;j/=3, k++){
				int sel = j%3;
				if(!sel) continue;
				else if(sel==1) A += price[k];
				else B += price[k];
			}
			mp[A-B] = max(mp[A-B], A+B);
		}

		for(int i = 0 ; i < pow3[R]; i++) {
			int A = 0, B = 0;
			for(int j = i, k = 0;j;j/=3, k++){
				int sel = j%3;
				if(!sel) continue;
				else if(sel==1) A += price[L+k];
				else B += price[L+k];
			}
			if(mp[B-A] || A==B) ans = min(ans, sum - (mp[B-A] + A + B));
		}

		printf("%d\n",ans);
	}

	return 0;
}
