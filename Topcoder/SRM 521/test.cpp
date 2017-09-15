#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class RangeSquaredSubsets {
public:
    int N;
    ll ans;
    map<ll,int> mp;
    vector<int> v;
    set<int> st;
    int inRange(int baseX, int baseY, int size, int x, int y, int op){
        if(op == 1) return baseX <= x && x <= baseX+size && baseY <= y && y <= baseY+size;
        else if(op == 2) return baseX - size <= x && x <= baseX && baseY <= y && y <= baseY + size;
        else if(op == 3) return baseX - size <= x && x <= baseX && baseY - size <= y && y <= baseY;
        return baseX <= x && x <= baseX + size && baseY - size <= y && y <= baseY;
    }

    void counter(vector<int>& x, vector<int>& y, int nlow, int nhigh, int op){
        for(int X : x){
            for(int Y : y){
                for(int size : v){
                    if(size < nlow || nhigh < size) continue;
                    ll mask = 0;
                    for(int i = 0 ; i < N; i++){
                        if(inRange(X, Y, size, x[i], y[i], op)) mask |= (1<<i);
                    }
                    if(mask && mp[mask] != 1) {
                        ans++, mp[mask] = 1;
                    }
                }
            }
        }
    }

    long long countSubsets(int nlow, int nhigh, vector<int> x, vector<int> y) {
        ans = 0;
        printf("\n");
        N = x.size();
        for(int X : x){
            for(int Y : y){
                for(int i = 0 ; i < N; i++){
                    if(x[i] < X || y[i] < Y) continue;
                    st.insert(max(x[i] - X, y[i] - Y));
                }
            }
        }
        for(int i = 0 ; i < N; i++) x.push_back(x[i]-1), x.push_back(x[i]+1);
        for(int i = 0 ; i < N; i++) y.push_back(y[i]-1), y.push_back(y[i]+1);

        st.insert(nlow);
        v.assign(st.begin(),st.end());
        for(int i = 1 ; i <= 4; i++) counter(x,y,nlow,nhigh,i);
        
        return ans;
    }
};

int main(){
    RangeSquaredSubsets obj;
    cout << obj.countSubsets(
    
    
100000000,
100000000,
{-5,0,5},
{0,0,0}



        );
    return 0;
}