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

int mx;
int main() {
	fastio();
    for(int i = 1; i <= 7; i++){
        vector<int> v;
        for(int j = 1; j <= i; j++) v.pb(j);
        do{
            if(v.back() % 2 == 0) continue;
            int num = 0;
            for(int k = 0; k < i; k++) num = num * 10 + v[k];
            int ok = 1;
            for(int k = 2; k * k <= num; k++) if(num % k == 0) ok = 0;
            if(ok && mx < num) mx = num;
        }while(next_permutation(all(v)));
    }
    cout << mx;

}
