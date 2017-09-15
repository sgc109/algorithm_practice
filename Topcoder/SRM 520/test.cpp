#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;


ll dp[21][200001];
ll way[21][2][200001];
class SRMIntermissionPhase {
public:
    int N;
    int countWays(vector<int> points, vector<string> description) {
        memset(dp,0,sizeof(dp));
        memset(way,0,sizeof(way));
        N = description.size();
        for(int i = 0 ; i < N; i++){
            for(int j = 1 ; j <= 200000; j++) way[i][0][j] = 1;
            for(int k = 1 ; k <= 3; k++){
                for(int j = 1 ; j <= 200000; j++){
                    int lo, hi;
                    if(description[i][k-1] == 'N') lo = hi = 0;
                    else lo = 1, hi = min(points[k-1], j);
                    way[i][k%2][j] = (way[i][k%2][j-1] + (way[i][(k+1)%2][j-lo] - (hi < j ? way[i][(k+1)%2][j-hi-1] : 0)) + mod) % mod;
                }
            }
        }
        for(int i = 0 ; i <= 200000; i++) dp[0][i] = 1;
        for(int i = 1 ; i <= N; i++) {
            for(int j = 1; j <= 200000; j++) {
                dp[i][j] = (dp[i][j-1] + (way[N-i][3%2][j] - way[N-i][3%2][j-1] + mod) % mod * dp[i-1][j-1] % mod) % mod;
                // if(j==1) printf("dp[%d][%d]:%lld\n",i,j,dp[i][j]);
            }
        }
        return (int)dp[N][200000];
    }
};

int main(){
    SRMIntermissionPhase obj;
    cout << obj.countWays(
        {25000, 50000, 100000}, {"YNN", "NNN"}


        );
    return 0;
}