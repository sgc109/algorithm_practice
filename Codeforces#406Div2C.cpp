#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;

int N;
int cntMv[2];
int moves[2][7003];
int canWin[2][7003];
int inDegree[2][7003];

const int LOSE = 1;
const int LOOP = 0;
const int WIN = 2;
const int NOTDET = 3;

int trans(int x){
	return x<0 ? x+N : x;
}
void go(int turn, int pos){
	for(int i = 0; i < cntMv[turn^1]; i++){
		int mov = moves[turn^1][i];
		int prev = trans(pos-mov);
		if(prev == 0 || canWin[turn^1][prev] != LOOP) continue;
		if(canWin[turn][pos] == LOSE) {
			canWin[turn^1][prev] = WIN;
			go(turn^1,prev);
		}
		else if(canWin[turn][pos] == WIN){
			inDegree[turn^1][prev]--;
			if(inDegree[turn^1][prev]==0) canWin[turn^1][prev] = LOSE, go(turn^1,prev);
		}
	}
}
int main() {
	fastio();
	cin >> N;

	for(int i = 0 ; i < 2; i ++){
		cin >> cntMv[i];
		for(int j = 0 ; j < cntMv[i]; j++)
			cin >> moves[i][j];
		for(int j = 0 ; j < N; j++)
			inDegree[i][j] = cntMv[i];
	}

	canWin[0][0] = canWin[1][0] = LOSE;
	inDegree[0][0] = inDegree[1][0] = 0;
	go(0,0);
	go(1,0);
	
	for(int i = 0 ; i < 2; i++){
		for(int j = 1 ; j < N; j++){
			if(canWin[i][j] == WIN) cout << "Win ";
			else if(canWin[i][j] == LOOP) cout << "Loop ";
			else cout << "Lose ";

		}
		cout << "\n";
	}
	return 0;
}
