#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int main() {
	ll i = 0;
	for(ll k = 1; ; k++){
		i += k;
		int cnt = 0;
		for(ll j = 1; j * j <= i; j++){
			if(i % j == 0) {
				cnt++;
				if(i != j * j) cnt++;
			}
		}
		if(cnt >= 500) {
			cout << i << endl;
			break;
		}
	}

	int num = 76576500;
	map<int,int> mp;
	for(int i = 2; i * i <= num; i++){
		while(num % i == 0) {
			mp[i]++;
			num /= i;
		}
	}
	if(num != 1) mp[num]++;
	for(auto it : mp){
		printf("%d %d\n", it.first, it.second);
	}
	return 0;
}