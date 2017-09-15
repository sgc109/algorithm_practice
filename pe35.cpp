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
string i2s(int num){
    string ret;
    while(num) ret += '0' + num % 10, num /= 10;
    return ret;
}
int s2i(string str){
    int ret = 0;
    while(sz(str)) ret = ret * 10 + str.back() - '0', str.pop_back();
    return ret;
}
int main() {
	fastio();
    for(int i = 2; i * i <= 1000000; i++){
        if(nop[i]) continue;
        for(int j = i * i; j <= 1000000; j += i){
            nop[j] = 1;
        }
    }

    int ans = 0;
    for(int num = 2; num <= 1000000; num++){
        string str = i2s(num);
        int ok = 1;
        for(int i = 0; i < sz(str); i++) {
            str = str.back() + str.substr(0, sz(str) - 1);
            int n = s2i(str);
            if(nop[n]) ok = 0;
        }
        ans += ok;
    }

    cout << ans;

	return 0;
}
