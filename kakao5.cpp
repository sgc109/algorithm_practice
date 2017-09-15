#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <cstdio>
using namespace std;

set<int> stX, stY;
vector<int> vX, vY;
int dp[5003][5003];

int solution(int n, vector<vector<int>> data) {
    stX.clear(), stY.clear();
    vX.clear(), vY.clear();
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i < n; i++){
        stX.insert(data[i][0]);
        stY.insert(data[i][1]);
    }
    vX.assign(stX.begin(), stX.end());
    vY.assign(stY.begin(), stY.end());
    for(int i = 0 ; i < n; i++){
        data[i][0] = lower_bound(vX.begin(), vX.end(), data[i][0]) - vX.begin() + 1;
        data[i][1] = lower_bound(vY.begin(), vY.end(), data[i][1]) - vY.begin() + 1;
        dp[data[i][0]][data[i][1]]++;
    }
    for(int i = 1 ; i <= 5000; i++){
        for(int j = 1 ; j <= 5000; j++){
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int x1 = data[i][0], y1 = data[i][1];
            int x2 = data[j][0], y2 = data[j][1];
            if(x1 == x2 || y1 == y2) continue;
            if(x1 + 1 == x2 || y1 + 1 == y2) {
                ans++;
                continue;
            }
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            int tmp = dp[x2 - 1][y2 - 1] - dp[x2 - 1][y1] - dp[x1][y2 - 1] + dp[x1][y1];
            if(tmp == 0) ans++;
        }
    }
    return ans;
}

int main(){
    cout << solution(4, {{0, 0}, {2, 2}, {0, 3}, {3, 0}});
}