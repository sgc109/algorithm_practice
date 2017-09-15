#include <vector>
#include <cstring>

using namespace std;

vector<vector<int> > pane;
int N, M;
bool inRange(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;    
}
int vis[103][103];
int dfs(int curI, int curJ, int col){
    if(vis[curI][curJ]) return 0;
    int ret = 1;
    vis[curI][curJ] = 1;
    for(int k = 0 ; k < 4; k++){
        int ni = curI + "2110"[k] - '1';
        int nj = curJ + "1201"[k] - '1';
        if(!inRange(ni, nj) || pane[ni][nj] != col) continue;
        ret += dfs(ni, nj, col);
    }
    return ret;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(vis,0,sizeof(vis));
    pane = picture;
    int ansCnt = 0, maxx = 0;
    N = (int)picture.size();
    M = (int)picture[0].size();
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(vis[i][j] || pane[i][j] == 0) continue;
            int ret = dfs(i, j, pane[i][j]);
            ansCnt++;
            maxx = max(maxx, ret);
        }
    }
    vector<int> answer(2);
    answer[0] = ansCnt;
    answer[1] = maxx;
    return answer;
}