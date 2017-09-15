#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int pane[1<<7][1<<7];
int T,K,N;
int holeI, holeJ;
string dy[] = {"112", "122", "112", "122"};
string dx[] = {"121", "112", "122", "101"};
int tileNum;
bool inRange(int i, int j){
	return 0 <= i && i < N && 0 <= j && j < N;
}
bool go(int hereI, int hereJ){
	if(hereJ == N) return go(hereI+1,0);
	if(hereI == N) return (tileNum-1) == (N*N-1)/3;
	for(int k = 0 ; k < 4; k++){
		bool imposs = false;
		for(int i = 0 ; i < 3; i++){
			int thereI = hereI + dy[k][i]-'1';
			int thereJ = hereJ + dx[k][i]-'1';
			if(!inRange(thereI, thereJ) || pane[thereI][thereJ] != 0) {
				imposs = true;
				break;
			}
		}
		if(imposs) continue;

		for(int i = 0 ; i < 3; i++){
			int thereI = hereI + dy[k][i]-'1';
			int thereJ = hereJ + dx[k][i]-'1';
			pane[thereI][thereJ] = tileNum;
		}
		tileNum++;
		if(go(hereI, hereJ+1)) return true;

		for(int i = 0 ; i < 3; i++){
			int thereI = hereI + dy[k][i]-'1';
			int thereJ = hereJ + dx[k][i]-'1';
			pane[thereI][thereJ] = 0;
		}
		tileNum--;
	}
	return false;
}

int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		tileNum = 1;
		memset(pane,0,sizeof(pane));
		cin >> K;
		N = 1<<K;
		cin >> holeJ >> holeI;
		holeJ--, holeI--;
		pane[holeI][holeJ] = -1;
		if(!go(0,0)) {
			cout << -1 << endl;
		}
		else {
			for(int i = N-1; i >= 0 ; i--){
				for(int j = 0 ; j < N; j++){
					cout << pane[i][j] << " ";
				}
				cout << "\n";
			}
		}
	}	
	return 0;
}
