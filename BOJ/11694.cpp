#include <cstdio>

int N, a, all1, res;
int main() {
	scanf("%d",&N);
	all1 = 1;
	for(int i = 0  ; i < N; i++) {
		scanf("%d",&a);
		if(a != 1) all1 = 0;
		res ^= a;
	}
	int c1 = all1;
	int c2 = res == 0;
	if(c1 ==c2) printf("koosaga");
	else printf("cubelover");
	return 0;
}