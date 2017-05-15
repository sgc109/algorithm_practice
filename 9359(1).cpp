#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

ll A,B,N;
vector<ll> dividers;

int main(){
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++){
		cin >> A >> B >> N;

		while(N > 1){
			bool divided = false;
			for(ll i = 2; i * i <= N; i++){
				if(N%i==0){
					dividers.push_back(i);
					divided = true;
					break;
				}
			}
			if(!divided) break;
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
		cout << "Case #" << t << ": " <<  B - A + 1 - ans << endl;
	}
	return 0;
}