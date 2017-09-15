#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> divisors;
long long N;
int main(){
	scanf("%lld",&N);
	for(long long i = 1; i * i <= N; i++){
		if(N % i == 0) {
			divisors.push_back(i);
			if(i != N/i) divisors.push_back(N/i);
		}
	}
	
	sort(divisors.begin(), divisors.end());

	for(int i = 0 ; i < divisors.size(); i++){
		printf("%lld ",divisors[i]);
	}
	return 0;
}