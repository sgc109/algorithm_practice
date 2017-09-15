// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
int solve[13];
int solvedP[13];
int checked[103];
int state[103][13];
int main() {
	cin >> N >> M;
	int ok = 1;
	for(int i = 0 ; i < N; i++){
		int K;
		cin >> K;
		solve[i] = K;
		if(!(0 < K && K < M)) {
			ok = 0;
			break;
		}
		for(int j = 0 ; j < M; j++){
			cin >> state[i][j];
			if(state[i][j] == 1) solvedP[j] = 1, checked[i]++;
		}
	}
	if(!ok){
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0 ; i < N; i++){
		int poss = solve[i] - checked[i];
		for(int j = 0 ; j < M && poss; j++){
			if(state[i][j] == -1 && solvedP[j] == 0) solvedP[j] = 1, poss--; 
		}
	}
	ok = 1;
	for(int i = 0 ; i < M; i++){
		if(solvedP[i] == 0) ok = 0;
	}

	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}