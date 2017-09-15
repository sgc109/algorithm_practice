#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class CorrectMultiplication {
public:
    ll a,b,c;
    ll f(ll A, ll C){
        return abs(A-a) + abs(C/A-b) + abs(C-c);
    }
    long long getMinimum(int _a, int _b, int _c) {
        a = _a, b = _b, c = _c;
        ll ret = 1e18;
        ll aLo = 1, aHi = 1e9;
        while(aLo + 10000 < aHi){
            ll ans1 = 1e18, ans2 = 1e18;
            ll aM1 = (2*aLo+aHi)/3;
            ll aM2 = (aLo+2*aHi)/3;
            // printf("aM1:%lld, aM2:%lld\n",aM1,aM2);

            ll bLo = 1, bHi = 1e9;
            while(bLo + 10000 < bHi){
                ll bM1 = (2*bLo+bHi)/3;
                ll bM2 = (bLo+2*bHi)/3;
                
                ret = min(ret, f(aM1,bM1));
                ret = min(ret, f(aM1,bM2));
                if(f(aM1,bM1) < f(aM1,bM2)) bHi = bM2;
                else bLo = bM1;
            }
            for(ll i = bLo; i <= bHi; i++) ans1 = min(ans1, f(aM1,i));


            bLo = 1, bHi = 1e9;
            while(bLo + 10000 < bHi){
                ll bM1 = (2*bLo+bHi)/3;
                ll bM2 = (bLo+2*bHi)/3;
                
                ret = min(ret, f(aM2,bM1));
                ret = min(ret, f(aM2,bM2));
                if(f(aM2,bM1) < f(aM2,bM2)) bHi = bM2;
                else bLo = bM1;
            }

            for(ll i = bLo; i <= bHi; i++) ans2 = min(ans2, f(aM2,i));

            if(ans1 < ans2) aHi = aM2;
            else aLo = aM1;
        }

        for(ll i = aLo; i <= aHi; i++) {
            ll bLo = 1, bHi = 1e9;
            while(bLo + 10000 < bHi){
                ll bM1 = (2*bLo+bHi)/3;
                ll bM2 = (bLo+2*bHi)/3;
                
                if(f(i,bM1) < f(i,bM2)) bHi = bM2;
                else bLo = bM1;
            }
            for(ll j = bLo; j <= bHi; j++) {
                ret = min(ret, f(i,j));
            }
        }

        return ret;
    }
};

int main(){
	CorrectMultiplication obj;
	cout << obj.getMinimum(

249999999, 4, 999999994
		);
	return 0;
}