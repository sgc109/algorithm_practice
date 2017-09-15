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

vector<pair<int,int> > divide(int num){
    vector<pair<int,int> > ret;
    int now = num;
    for(int i = 2; i * i <= num; i++){
        int cnt = 0;
        while(now % i == 0) cnt++, now /= i;
        if(cnt) ret.pb({i, cnt});
    }
    if(now != 1) ret.pb({now, 1});
    return ret;
}
vector<pair<int,int> > divs[103];
set<vector<pair<int,int> > > st;
int main() {
	fastio();
    for(int i = 2; i <= 100; i++) {
        divs[i] = divide(i);
        for(int j = 2; j <= 100; j++){
            vector<pair<int,int> > tmp;
            for(auto p : divs[i]){
                tmp.pb({p.first, p.second * j});
            }
            st.insert(tmp);
        }
    }
    cout << sz(st);

	return 0;
}
