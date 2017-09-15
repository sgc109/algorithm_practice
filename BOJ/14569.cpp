#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

long long subjects[1003];
long long students[10003];
int N,M;
int main() {
	memset(students,-1,sizeof(students));

	scanf("%d",&N);
	for(int i = 0 ; i < N; i++){
		int k;
		scanf("%d",&k);
		for(int j = 0 ; j < k; j++){
			int a;
			scanf("%d",&a);
			subjects[i] |= (1ll << a);
		}
	}

	scanf("%d",&M);
	for(int i = 0 ; i < M; i++){
		int k;
		scanf("%d",&k);
		for(int j = 0 ; j < k; j++){
			int a;
			scanf("%d",&a);
			students[i] ^= (1ll << a);
		}
	}

	for(int i = 0 ; i < M; i++){
		int ans = 0;
		for(int j = 0 ; j < N; j++){
			if((students[i] ^ subjects[j]) == (students[i] | subjects[j])) ans++;
		}
		printf("%d\n",ans);
	}

	return 0;
}
