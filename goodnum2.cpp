#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
int A[5003];
int check2[400003];
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(check2,0,sizeof(check2));
		scanf("%d",&N);
		int ans = 0;
		for(int i = 0 ; i < N; i++) scanf("%d",A+i);
		for(int i = 0 ; i < N; i++){
			bool isgood = false;
			for(int j = 0 ; j < i; j++) if(check2[A[i] - A[j] + 200000]) isgood = true;
			for(int j = 0 ; j <= i; j++) check2[A[j] + A[i] + 20000] = 1;
			if(isgood) ans++;
		}
		printf("Case #%d\n%d\n",t,ans);
	}
	return 0;
}