#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

ll d[30003];
int check[30003];
ll maxx;
int main() {
	for(int i = 1; i <= 30000; i++){
		ll sum = 0;
		for(int j = 1; j * j <= i; j++){
			if(i % j == 0){
				sum += j;
				if(j * j != i) sum += i / j;
			}
		}
		sum -= i;
		d[i] = sum;
	}

	for(int i = 2; i <= 30000; i++){
		for(int j = i; j <= 30000; j++){
			if(d[i] > 30000 || d[j] > 30000) continue;
			if(d[i] == j && d[j] == i) check[i] = check[j] = 1;
		}
	}

	ll sum = 0;
	for(int i = 1; i <= 10000; i++) if(check[i]) sum += i;
	cout << sum;
	return 0;
}