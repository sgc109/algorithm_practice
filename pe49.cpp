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

vector<string> nums;
void go(int pos, string s){
    if(pos == 4){
        nums.pb(s);
        return;
    }
    int start = sz(s) ? s.back() - '0' : 1;
    for(int i =  start; i <= 9; i++){
        string nxt = s + (char)('0' + i);
        go(pos + 1, nxt);
    }
}
int main() {
	fastio();
    go(0, "");
}
