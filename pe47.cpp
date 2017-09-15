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

int divCnt(int x){
    int ret = 0;
    for(int i = 2; i * i <= x && x > i; i++){
        if(x % i) continue;
        ret++;
        while(x % i == 0) x /= i;
    }
    if(x != 1) ret++;
    return ret;
}
int cnt[10000003];
int main() {
	fastio();
    for(int i = 2; i <= 1000000; i++){
        cnt[i] = divCnt(i);
    }
    int con = 0;
    for(int i = 2; i <= 1000000; i++){
        if(cnt[i] == 4) con++;
        else con = 0;
        if(con == 4) {
            cout << i << endl;
            break;
        }
    }
}
