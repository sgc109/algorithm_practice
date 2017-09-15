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

struct Number{
    vector<int> v;
    Number(vector<int> init){
        v = init;
    }
    Number(int size){
        v = vector<int>(size, 0);
    }
    Number operator+(Number& rhs) {
        vector<int> retV;
        int szA = sz(v), szB = sz(rhs.v);
        for(int i = 0; i < max(szA, szB); i++){
            int l = (i < szA ? v[i] : 0);
            int r = (i < szB ? rhs.v[i] : 0);
            retV.pb(l + r);
        }
        retV.pb(0);
        for(int i = 0; i < sz(retV) - 1; i++) {
            retV[i + 1] += retV[i] / 10, retV[i] %= 10;
        }
        if(retV.back() == 0) retV.pop_back();
        Number ret(retV);
        return ret;
    }
    void print(){
        for(int i = sz(v) - 1; i >= 0; i--) cout << v[i];
    }
};
vector<Number> fibo;
int main() {
	fastio();
    vector<int> v;
    v.pb(1);
    fibo.pb(Number(v));
    fibo.pb(Number(v));
    for(int i = 3; ; i++){
        fibo.pb(fibo[sz(fibo) - 2] + fibo.back());
        if(sz(fibo.back().v) >= 1000) {
            cout << i << endl;
            break;
        }
    }


	return 0;
}
