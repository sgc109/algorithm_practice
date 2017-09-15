#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int f[11];
int ord[11];
int main() {
	f[0] = 1;
	for(int i = 1; i <= 10; i++) f[i] = f[i - 1] * i;
	int K = 1000000;
	for(int i = 0 ; i < 10; i++){
		for(int j = 9 - i; j >= 0; j--){
			if(f[9 - i] * j < K){
				ord[i] = j;
				K -= f[9 - i] * j;
				break;
			}
		}
	}
	vector<int> v;
	for(int i = 0 ; i < 10; i++) v.pb(i);
	for(int i = 0 ; i < 10; i++){
		cout << v[ord[i]];
		v.erase(v.begin() + ord[i]);
	}
	return 0;
}