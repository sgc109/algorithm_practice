#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<queue>

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)
#define LONG long long
#define INF 0x3a3a3a3a

const LONG MOD = 1000000007;

using namespace std;

LONG fermat(LONG a) {
    LONG result = 1;
    int tmp = MOD - 2;
    
    while(tmp) {
        if(tmp & 1) result = (result * a) % MOD;
        tmp /=2;
        a = (a*a) % MOD;
    }
    return result;
}

LONG fact(LONG n) {
    LONG ret = 1;
    for(LONG i = 1; i <= n; ++i) {
        ret = (ret * i) % MOD;
    }
    return ret;
}

long long mod_exp(long long a,long long b,long long c) // yukariko
{
	a%=c;
	if(b==0)return 1;
	if(b==1)return a;
	if(b&1) return (a*mod_exp((a*a)%c,(b-1)/2,c))%c;
	return mod_exp((a*a)%c,b/2,c);
}

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    
    printf("%lld",(((fact(a)*fermat(fact(a-b))) % MOD)*fermat(fact(b))) % MOD);
    
    return 0;
}