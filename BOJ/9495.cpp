#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int counted[53][53];
int vis[53][53];
char pane[53][53];
int grp[53][53];
int wCnt[2503], mustCnt[2503];
int cnt;
int mcnt;
int N;
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < N;
}

struct cell{
	int i, j, grp;
	bool operator<(const cell& rhs) const{
		int f1 = mustCnt[grp] - wCnt[grp];
		int f2 = mustCnt[rhs.grp] - wCnt[rhs.grp];
		if(f1 != f2) return f1 > f2;
		int s1 = 0, s2 = 0;
		for(int k = 0 ; k < 4; k++){
			int ni = i + "2110"[k] - '1';
			int nj = j + "1201"[k] - '1';
			if(!inRange(ni, nj)) continue;
			if(pane[ni][nj] == 'o') s1++;
		}
		for(int k = 0 ; k < 4; k++){
			int ni = rhs.i + "2110"[k] - '1';
			int nj = rhs.j + "1201"[k] - '1';
			if(!inRange(ni, nj)) continue;
			if(pane[ni][nj] == 'o') s2++;
		}
		return s1 < s2;
	}
};
vector<cell> cells;

int dfs(int curI, int curJ){
	if(vis[curI][curJ]) return 0;
	vis[curI][curJ] = 1;
	int ret = 1;
	for(int k = 0 ; k < 4; k++){
		int ni = curI + "2110"[k] - '1';
		int nj = curJ + "1201"[k] - '1';
		if(!inRange(ni, nj)) continue;
		if(pane[ni][nj] == '.' && !counted[ni][nj]) mcnt++, counted[ni][nj] = 1; 
		if(pane[ni][nj] == 'o') ret += dfs(ni, nj);
	}
	return ret;
}
void printPane(){
	for(int i = 0 ; i < N; i++){
		cout << pane[i] << endl;
	}
	cout << endl;
}
int main() {
	memset(grp,-1,sizeof(grp));
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> pane[i];
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			memset(counted,0,sizeof(counted));
			if(pane[i][j] != 'o' || vis[i][j]) continue;
			mcnt = 0;
			wCnt[cnt] = dfs(i, j);
			mustCnt[cnt] = mcnt;
			cnt++;
		}
	}
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < N; j++){
			if(pane[i][j] != '.') continue;
			cells.pb(cell{i, j, grp[i][j]});
		}
	}
	int ans = 0;
	int cur = sz(cells);
	while(!cells.empty()){
		printPane();
		sort(all(cells));
		auto c = cells.back();
		ans = max(ans, cur);
		cur += (mustCnt[c.grp] == 1 ? wCnt[c.grp] : 0) - 1;
		for(int k = 0 ; k < 4; k++){
			int ni = c.i + "2110"[k] - '1';
			int nj = c.j + "1201"[k] - '1';
			if(!inRange(ni, nj)) continue;
			if(pane[ni][nj] == 'o') mustCnt[grp[ni][nj]]--;
		}
		pane[c.i][c.j] = 'x';
		cells.pop_back();
	}
	ans = max(ans, cur);

	cout << ans;
	return 0;
}