#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int my_pow(int x, int n){
    int ret = 1;
    while(n--) ret *= x;
    return ret;
}
int main() {
	fastio();
    int up = 5;
    int ans = 0;
    for(int num = 2; num <= 1000000; num++){
        int now = num;
        int sum = 0;
        while(now) sum += my_pow(now % 10, up), now /= 10;
        if(num == sum) ans += num;
    }
    cout << ans;

	return 0;
}
