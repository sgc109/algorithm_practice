#include <cstdio>
int N, a;
int main() {
	int ans = 0;
	scanf("%d", &N);
	for(int i = 0 ; i < N; i++){
		scanf("%d", &a);
		if(!a) ans ^= 0;
		else {
			if(a % 4 == 0) ans ^= a - 1;
			else if(a % 4 == 1 || a % 4 == 2) ans ^= a;
			else ans ^= a + 1;
		}
	}
	if(ans) printf("koosaga");
	else printf("cubelover");
	return 0;
}	