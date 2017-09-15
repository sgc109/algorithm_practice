#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

set<ll> st;
class CountingSeries {
public:
    long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
        st.clear();
        if(d == 1 && c <= upperBound) st.insert(c);
        else for(ll i = c; i <= upperBound; i*=d) st.insert(i);

        ll ret = (upperBound - a) / b + 1;
        if(upperBound < a) ret = 0;

        for(auto it = st.begin(); it != st.end(); it++){
            ll g = (*it);
            if(g >= a && (g - a) % b == 0) ret--;
        }

        ret += st.size();

        return ret;
    }
};

int main(){
    CountingSeries obj;
    cout << obj.countThem(17340, 40451, 7763, 1, 3462);
    return 0;
}