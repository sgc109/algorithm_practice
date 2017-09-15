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

set<int> st;
int main() {
	fastio();
    int mx = 0, mxNum;
    for(int i = 2; i <= 1000; i++){
        st.clear();
        int len = 0;
        int rest = 1;
        while(1){
            if(!rest || st.count(rest)) break;
            st.insert(rest);
            while(rest < i) len++, rest *= 10;
            rest %= i;
        }
        if(mx < len) mx = len, mxNum = i;
    }
    cout << mx << ' ' << mxNum;

	return 0;
}
