#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll mod = 1e9;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

ll mypow(ll x, int n){
    if(!n) return 1;
    if(n & 1) return x * mypow(x, n - 1) % mod;
    return mypow(x * x % mod, n / 2);
}
int main() {
    fastio();
    ll ans = 0;
    for(int i = 1; i <= 1000; i++){
        ll add = mypow(i, i);
        ans = (ans + add) % mod;
    }
    cout << ans;
}
