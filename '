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

int exist[10][10];
int main() {
	fastio();
    for(int i = 1; i <= 10000000; i++){
        memset(exist,0,sizeof(exist));
        for(int j = 1; j <= 6; j++){
            int now = i * j;
            while(now) exist[j][now % 10] = 1, now /= 10;
        }
        int ok = 1;
        for(int j = 2; j <= 6; j++) {
            for(int k = 0; k < 10; k++){
                if(exist[1][k] != exist[j][k]) ok = 0;
            }
        }
        if(!ok) continue;
        cout << i;
        break;
    }

}
