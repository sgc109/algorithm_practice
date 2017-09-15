#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T,N;
int check[10];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(check,0,sizeof(check));
		scanf("%d",&N);
		while(N){
			check[N%10] = 1;
			N/=10;
		}
		int ans = 0;
		for(int i = 0 ; i < 10 ; i++)
			ans += check[i];
		printf("%d\n",ans);
	}
	return 0;
}