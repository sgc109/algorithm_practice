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

int nop[10000003];
vector<int> primes;
int isSqr(int x){
    int lo = 1, hi = 10000;
    while(lo < hi){
        int mid = lo + hi >> 1;
        if(mid * mid == x) return 1;
        else if(mid * mid < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo * lo == x;
}
int main() {
	fastio();
    for(int i = 2; i * i <= 10000000; i++){
        if(nop[i]) continue;
        for(int j = i * i; j <= 10000000; j+= i) nop[j] = 1;
    }
    nop[1] = 1;
    for(int i = 2; i <= 10000000; i++) if(!nop[i]) primes.pb(i);
    for(int i = 9; i <= 10000000; i += 2){
        if(!nop[i]) continue;
        int ok = 0;
        for(int p : primes) {
            if(p >= i) break;
            int rest = i - p;
            if(rest % 2) continue;
            rest /= 2;
            if(isSqr(rest)) {
                ok = 1;
                break;
            }
        }
        if(!ok) {
            cout << i << endl;
            return 0;
        }
    }
}
