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

string i2bins(int num){
    string ret;
    while(num) ret += '0' + num % 2, num /= 2;
    return ret;
}
string i2decs(int num){
    string ret;
    while(num) ret += '0' + num % 10, num /= 10;
    return ret;
}
int main() {
	fastio();
    int ans = 0;
    for(int num = 1; num <= 1000000; num++){
        string s1 = i2bins(num);
        string s2 = i2decs(num);
        int ok = 1;
        for(int i = 0; i < sz(s1) / 2; i++) if(s1[i] != s1[sz(s1) - 1 - i]) ok = 0;
        for(int i = 0; i < sz(s2) / 2; i++) if(s2[i] != s2[sz(s2) - 1 - i]) ok = 0;
        if(ok) ans += num, cout << num << endl;
    }
    cout << ans;
	return 0;
}
