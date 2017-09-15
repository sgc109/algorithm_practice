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

int nop[1000003];
vector<int> ps;
int main() {
	fastio();
    for(int i = 2; i * i <= 1000000; i++){
        if(nop[i]) continue;
        for(int j = i * i; j <= 1000000; j += i){
            nop[j] = 1;
        }
    }
    for(int i = 2; i <= 1000000; i++) if(!nop[i]) ps.pb(i);
    for(int len = sz(ps); len >= 1; len--){
        int sum = 0;
        for(int i = 0; i < len && sum <= 1000000; i++) sum += ps[i];
        for(int i = len; i <= 1000000 && sum <= 1000000; i++) {
            if(!nop[sum]) return !printf("%d", sum);
            sum -= ps[i - len];
            sum += ps[i];
        }
    }
}
