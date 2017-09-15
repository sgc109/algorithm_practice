#include <cstdio>

int N, a, all1, res;
int main() {
	scanf("%d",&N);
	for(int i = 0  ; i < N; i++) {
		scanf("%d",&a);
		res ^= a;
	}
	if(res) printf("koosaga");
	else printf("cubelover");
	return 0;
}