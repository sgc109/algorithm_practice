#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
int check[53];
int tim[53];
vector<int> X, Y;
string dir;
int poss(int i, int j){
    if(X[i] == X[j]){
        if(Y[i] < Y[j]) swap(i, j);
        if(dir[i] == 'S' && dir[j] == 'N') return abs(Y[i] - Y[j]);
        return 0;
    }
    else if(Y[i] == Y[j]){
        if(X[i] > X[j]) swap(i, j);
        if(dir[i] == 'E' && dir[j] == 'W') return abs(X[i] - X[j]);
        return 0;
    }
    if(abs(X[i] - X[j]) != abs(Y[i] - Y[j])) return 0;
    if(X[i] > X[j]) swap(i, j);
    if(X[i] < X[j] && Y[i] < Y[j]){
        if((dir[i] == 'N' && dir[j] == 'W') || (dir[i] == 'E' && dir[j] == 'S')) return 2 * abs(X[i] - X[j]);
        return 0;
    }
    if((dir[i] == 'E' && dir[j] == 'N') || (dir[i] == 'S' && dir[j] == 'W')) return 2 * abs(X[i] - X[j]);
    return 0;
}
vector<pair<int, pair<int,int> > > v;
class AntsMeet {
    public:
    int countAnts(vector<int> x, vector<int> y, string direction) {
        X = x, Y = y, dir = direction;
        v.clear();
        memset(tim,0,sizeof(tim));
        memset(check,0,sizeof(check));
        N = (int)x.size();
        for(int i = 0 ; i < N; i++){
            for(int j = i + 1; j < N; j++){
                int t = poss(i, j);
                if(!t) continue;
                v.push_back({t, {i, j}});
            }
        }
        sort(v.begin(), v.end());
        for(auto p : v){
            int i = p.second.first;
            int j = p.second.second;
            int cst = p.first;
            if(tim[i] && tim[i] < cst) continue;
            if(tim[j] && tim[j] < cst) continue;
            tim[i] = tim[j] = cst;
            check[i] = check[j] = 1;
        }
        int ans = 0;
        for(int i = 0 ; i < N; i++) ans += !check[i];

        return ans;
    }
};

int main(){
    AntsMeet obj;
    cout << obj.countAnts({0, 1, 2}, {0, 0, 0}, "EWW");
    return 0;
}