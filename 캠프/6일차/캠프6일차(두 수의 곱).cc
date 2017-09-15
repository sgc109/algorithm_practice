#include <cstdio>
#include <cmath>
using namespace std;
int A,B,C;
int a,b,c;
int main() {
	int ans=INF;
	scanf("%d%d%d",&a,&b,&c);
	for(int i = 1; i <= 4000000; i++){
		for(int j = 1; i*j<=a+b+2*c-3; j++){
			ans=min(ans,abs(a-i)+abs(b-j)+abs(c-i*j));
		}
	}
	printf("%d",ans);
	return 0;
}
