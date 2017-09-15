#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

ll A,B,N;
int notPrime[100003];
vector<int> primes;
map<ll, int> mp;
vector<ll> dividers;

int main(){

	for(int i = 2; i <= 100000; i++){
		if(notPrime[i]) continue;
		for(int j = 2*i; j <= 100000; j+=i){
			notPrime[j] = 1;
		}
	}

	for(int i = 2; i <= 100000; i++){
		if(!notPrime[i]) primes.push_back(i);
	}
	cin >> A >> B >> N;

	while(N > 1){
		bool divided = false;
		for(auto p : primes){
			if(N % p == 0) {
				N /= p; 
				mp[p] = 1;
				divided = true;
				break;
			}
		}
		if(!divided) break;
	}

	if(N != 1) mp[N] = 1;

	for(auto it = mp.begin(); it != mp.end(); it++){
		dividers.push_back((*it).first);
	}

	int size = dividers.size();
	ll ans = 0;
	for(int i = 0 ; i < 1<<size ; i++){
		if(!i) continue;
		int cnt = 0;
		ll div = 1;
		for(int j = 0 ; j < size; j++){
			if(i&(1<<j)) div *= dividers[j], cnt++;
		}
		ll lo = (A+div-1)/div*div;
		ll hi = B/div*div;
		if(lo>hi) continue;
		ll gasu = (hi-lo)/div + 1;
		ans += cnt%2 ? gasu : -gasu;
	}
	cout << B - A + 1 - ans << endl;
	
	return 0;
}