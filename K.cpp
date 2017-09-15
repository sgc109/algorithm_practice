#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N, M, K;
int in[100003];
int must[100003];
vector<int> G[100003];
int made[100003];
void NO(){
	cout << "Lier!";
	exit(0);
}
int main(){
	cin.sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K;
	for(int i = 0 ; i < M ; i++){
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		must[b]++;
	}
	for(int i = 0 ; i < K; i++){
		int o, a;
		cin >> o >> a;
		if(o == 1){
			if(in[a] != must[a]) NO();
			if(!made[a]) for(int to : G[a]) in[to]++;
			made[a]++;
		}
		else {
			if(!made[a]) NO();
			if(made[a] == 1) for(int to : G[a]) in[to]--;
			made[a]--;
		}
	}
	cout << "King-God-Emperor";
	return 0;	
}