#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int MOD = 20170805;
int dp[503][503][2];
int N, M;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp,0,sizeof(dp));
    N = (int)city_map.size();
    M = (int)city_map[0].size();
    dp[1][1][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(i == 1 && j == 1) continue;
            
            int& cache0 = dp[i][j][0];
            if(j == 1) cache0 = 0;
            else{
                int mp = city_map[i - 1][j - 2];
                if(mp == 0) cache0 = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                else if(mp == 1) cache0 = 0;
                else cache0 = dp[i][j - 1][0];
            }
            
            int& cache1 = dp[i][j][1];
            if(i == 1) cache1 = 0;
            else {
                int mp = city_map[i - 2][j - 1];
                if(mp == 0) cache1 = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                else if(mp == 1) cache1 = 0;
                else cache1 = dp[i - 1][j][1];
            }
        }
    }
    
    
    int answer = (dp[N][M][0] + dp[N][M][1]) % MOD;
    return answer;
}