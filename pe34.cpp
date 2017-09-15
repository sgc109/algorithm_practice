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

int fact(int n){
    if(!n) return 1;
    return n * fact(n - 1);
}
int main() {
	fastio();
    int up = 5;
    int ans = 0;
    for(int num = 3; num <= 10000000; num++){
        int now = num;
        int sum = 0;
        while(now) sum += fact(now % 10), now /= 10;
        if(num == sum) ans += num;
    }
    cout << ans;

	return 0;
}
