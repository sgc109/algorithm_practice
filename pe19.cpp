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

int isYoon(int y){
    if(y % 400 == 0) return 1;
    if(y % 100 == 0) return 1;
    return y % 4 == 0;
}
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	fastio();
    int year = 1900;
    int sum = 0;
    int ans = 0;
    while(year < 2001){
        for(int mon = 1; mon <= 12; mon++){
            if(1901 <= year && sum == 6) ans++;
            sum = (sum + days[mon] + (mon == 2 && isYoon(year) ? 1 : 0)) % 7;
        }
        year++;
    }
    cout << ans;
	return 0;
}
