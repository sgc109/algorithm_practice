#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct tower{
	int x,y,pow;
};
int N,R,t1,t2;
tower towers[303];
vector<int> G[303];
int aMatch[303], bMatch[303];
vector<tower> A,B;
int cntA, cntB;
int visited[303];
int whichG(int x){
	return (towers[t1].y - towers[t2].y) * (towers[x].x - towers[t1].x) > (towers[t1].x - towers[t2].x) * (towers[x].y - towers[t1].y);
}
int dfs(int a){
	if(visited[a]) return 0;
	visited[a] = 1;
	for(int b : G[a]){
		if(bMatch[b] == -1 || dfs(bMatch[b])){
			aMatch[a] = b;
			bMatch[b] = a;
			return 1;
		}
	}
	return 0;
}
int pow2(int x){return x*x;}
int dist(tower a, tower b){
	return pow2(a.x - b.x) + pow2(a.y - b.y);
}
int main() {
	for(int t = 1; ; t++){
		cin >> N;
		if(!N) break;
		for(int i = 0 ; i < 303; i++) G[i].clear();
		memset(aMatch,-1,sizeof(aMatch));
		memset(bMatch,-1,sizeof(bMatch));
		A.clear();
		B.clear();

		for(int i = 1; i <= N; i++) {
			int a,b,c;
			cin >> a >> b >> c;
			towers[i] = tower{a,b,c};
		}
		cin >> t1 >> t2 >> R;
		for(int i = 1 ; i <= N; i++) {
			if(!towers[i].pow) continue;
			if(whichG(i)) A.push_back(towers[i]);
			else B.push_back(towers[i]);
		}
		if(A.size() > B.size()) swap(A,B);
		cntA = A.size();
		cntB = B.size();

		for(int i = 0 ; i < cntA; i++) {
			for(int j = 0 ; j < cntB; j++){
				if(A[i].pow > B[j].pow && dist(A[i], B[j]) <= R*R) G[i].push_back(j);
			}
		}
		int ans = 0;
		for(int i = 0 ; i < cntA; i++){
			memset(visited,0,sizeof(visited));
			if(dfs(i)) ans++;
		}
		cout << "Case " << t << ": ";
		cout << ans << endl;
	}

	return 0;
}