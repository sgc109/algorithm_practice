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
int fromLeft(int num){
    int upper = 1;
    int ok = 1;
    while(upper < num) upper *= 10;
    while(num){
        if(nop[num]) ok = 0;
        int mok = num / upper;
        num %= upper;
        upper /= 10;
    }
    return ok;
}
int fromRight(int num){
    int ok = 1;
    while(num) {
        if(nop[num]) ok = 0;
        num /= 10;
    }
    return ok;
}
int main() {
	fastio();
    for(int i = 2; i * i <= 10000000; i++){
        if(nop[i]) continue;
        for(int j = i * i; j <= 10000000; j += i) nop[j] = 1;
    }
    nop[1] = 1;
    int ans = 0;
    for(int i = 11; i <= 10000000; i++){
        if(fromLeft(i) && fromRight(i)) ans += i;
    }
    cout << ans;
}
