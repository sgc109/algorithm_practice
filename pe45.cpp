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
const ll MAXN = 100000000;
ll getTri(ll x){
    return x * (x + 1) / 2;
}
ll getFiv(ll x){
    return x * (3 * x - 1) / 2;
}
ll getSix(ll x){
    return x * (2 * x - 1);
}
int check(ll x, int base){
    ll lo = 1, hi = MAXN;
    while(lo < hi){
        ll mid = lo + hi >> 1;
        ll tmp;
        if(base == 3) tmp = getTri(mid);
        else if(base == 5) tmp = getFiv(mid);
        else tmp = getSix(mid);
        if(tmp == x) return 1;
        else if(tmp < x) lo = mid + 1;
        else hi = mid - 1;
    }
    if(base == 3) return getTri(lo) == x;
    if(base == 5) return getFiv(lo) == x;
    return getSix(lo) == x;
}
int main() {
	fastio();
    for(ll i = 1; i <= 1000000; i++){
        ll num = getSix(i);
        if(check(num, 3) && check(num, 5)) cout << num << '\n';
    }
}
