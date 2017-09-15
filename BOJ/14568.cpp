#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int main() {
	int N;
	scanf("%d",&N);
	int ans = 0;
	for(int i = 0 ; i <= N; i++){
		for(int j = 0 ; j <= N; j++){
			for(int k = 0 ; k <= N; k++){
				if(i+j+k != N) continue;
				if(!i || !j || !k) continue;
				if(i < j+2) continue;
				if(k%2) continue;
				ans++;
			}
		}
	}

	printf("%d",ans);	
	return 0;
}
