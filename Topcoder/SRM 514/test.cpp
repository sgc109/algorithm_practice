#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
class MagicalGirlLevelTwoDivOne {
public:
    int theCount(vector<string> palette, int n, int m);
};

int N,M;
ll dp[13][1<<10];
int pane[53][53];
int correct[13][13];
int cnts[13][13];
ll pow4[2503], pow5[2503];
ll go(int row, int state){
    if(row == N) return state == ((1<<M)-1);
    ll& cache = dp[row][state];
    if(cache != -1) return cache;
    cache = 0;
    for(int i = 0 ; i < (1<<M); i++){
        int cnt= 0;
        for(int j = i; j ; j>>=1) cnt+=(j&1);
        if(cnt%2==0) continue;
        bool ok = true;
        ll mult = 1;
        for(int j = 0 ; j < M; j++){
            if(correct[row][j] != -1 && correct[row][j] != ((i&(1<<j))>>j)) {ok = false; break;}
            if(correct[row][j] == -1) mult = (mult * (((i&(1<<j))>>j)?pow5[cnts[row][j]]:pow4[cnts[row][j]])) % MOD;
        }
        if(ok) cache = (cache + (mult * go(row+1, state^i)) % MOD) % MOD;
    }
    return cache;
}

int MagicalGirlLevelTwoDivOne::theCount(vector<string> palette, int n, int m) {
    pow4[0] = pow5[0] = 1;
    for(int i = 1 ; i < 2503; i++) pow4[i] = (pow4[i-1] * 4) % MOD, pow5[i] = (pow5[i-1] * 5) % MOD;
    memset(dp,-1,sizeof(dp));
    memset(correct,-1,sizeof(correct));
    memset(pane,-1,sizeof(pane));
    memset(cnts,0,sizeof(cnts));
    N = n, M = m;
    int nn = palette.size();
    int mm = palette[0].size();
    for(int i = 0 ; i < nn; i++) for(int j = 0 ; j < mm; j++) {if(palette[i][j]=='.') continue; pane[i][j] = (palette[i][j]-'0')%2;}
    for(int i = 0 ; i < nn; i++){
        for(int j = 0 ; j < mm; j++){
            if(pane[i][j] == -1) {cnts[i%N][j%M]++; continue;}
            if(correct[i%N][j%M] == -1) {correct[i%N][j%M] = pane[i][j]; continue;}
            if(correct[i%N][j%M] != pane[i][j]) return 0;
        }
    }
    return (int)go(0, 0);
}


int main(){
    MagicalGirlLevelTwoDivOne obj;
    cout << obj.theCount(
{"..",
 "4."},
2,
2);

    return 0;
}