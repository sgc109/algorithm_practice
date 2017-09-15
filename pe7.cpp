#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int np[1000003];
int main() {
	np[0] = np[1] = 1;
	for(int i = 2; i * i <= 1000000; i++){
		if(np[i]) continue;
		for(int j = i * i; j <= 1000000; j += i) np[j] = 1;
	}
	int cnt = 0;
	for(int i = 0 ; i <= 1000000; i++) {
		cnt += !np[i];
		if(cnt == 10001) {
			cout << i;
			break;
		}
	}
	return 0;
}