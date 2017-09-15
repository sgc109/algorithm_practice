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

int findNum(int kth){
    int sum = 0;
    for(int i = 1, base = 9; ; i++, base *= 10){
        if(kth <= sum + i * base){
            kth -= sum;
            int th = (kth - 1) / i;
            int n = base / 9 + th;
            int md = (kth - 1) % i;
            for(int j = 0; j < i - md - 1; j++) n /= 10;
            return n % 10;
        }
        sum += i * base;
    }
}
int main() {
	fastio();
    int ans = 1;
    for(int i = 0, base = 1; i < 7; i++, base *= 10){
        ans *= findNum(base);
    }
    cout << ans;

	return 0;
}
