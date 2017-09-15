#include <stdio.h>


const int MOD = 1000000007;

int fermat(int n) {
	int power = MOD - 2;
	long long ret = 1;
	long long start = n;
	while(power) {
		if(power & 1) ret = (ret*start) % MOD;
		start = (start * start) % MOD;
		power >>= 1;
	}
	return ret % MOD;
}

int main(){
	long long aLong = 1000000000;
	long long bLong = 100000007;
	long long cLong = 2;

	int a = 1000000000;
	int b = 100000007;
	int c = 2;

	printf("%d\n",(aLong*bLong/cLong)%MOD);
	printf("%d\n",((((long long)a*b)%MOD)*fermat(c))%MOD);


	return 0;
}