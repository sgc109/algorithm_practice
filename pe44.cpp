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

ll getFive(ll x){
    return x * (3 * x - 1) / 2;
}
int isFive(ll x){
    if(x < 1) return 0;
    ll lo = 1, hi = 10000;
    while(lo < hi){
        ll mid = lo + hi >> 1;
        ll fv = getFive(mid);
        if(fv == x) return 1;
        else if(fv < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return getFive(lo) == x;
}
ll mn;
int main() {
	fastio();
    mn = infl;
    for(int i = 1; i < 5000; i++){
        for(int j = 1; j < 5000; j++){
            ll a = getFive(i);
            ll b = getFive(j);
            if(isFive(a + b) && isFive(abs(a - b))) mn = min(mn, abs(a - b));
        }
    }
    cout << mn;
}
