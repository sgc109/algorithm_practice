#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

map<string,int> num[2];
int cnt[2];
map<string,int> already;
string S;
int ans;
int aMatch[1503], bMatch[1503];
int iter[1503];
int level[1503];
vector<int> G[1503];
int cntA, cntB;
map<int,int> check;
bool isUpper(char c){
	return 'A' <= c && c <= 'Z';
}
void bfs(){
	queue<int> q;
	for(int a = 0 ; a < cntA; a++) if(aMatch[a] == -1) q.push(a), level[a] = 0;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		for(int b : G[a]){
			if(bMatch[b] == -1 || level[bMatch[b]] != -1) continue;
			level[bMatch[b]] = level[a] + 1;
			q.push(bMatch[b]);
		}
	}
}
bool dfs(int a){
	for(int& i = iter[a]; i < (int)G[a].size(); i++){
		int b = G[a][i];

		if(bMatch[b] == -1 || (level[bMatch[b]] == level[a] + 1 && dfs(bMatch[b]))){
			aMatch[a] = b;
			bMatch[b] = a;
			return true;	
		}
	}
	return false;
}
int hopcroft(){
	int ret = 0;
	while(1){
		memset(level,-1,sizeof(level));
		memset(iter,0,sizeof(iter));
		bfs();
		int add = 0;
		for(int a = 0 ; a < cntA; a++) if(level[a] == 0 && dfs(a)) add++;
		if(!add) break;
		ret += add;
	}
	return ret;
}
int main() {
	memset(aMatch,-1,sizeof(aMatch));
	memset(bMatch,-1,sizeof(bMatch));
	cin >> S;
	for(int i = 0 ; i < (int)S.size()-1; i++){
		string tmp = S.substr(i,2);
		int id = isUpper(tmp[0]);
		if(!num[id][tmp]) num[id][tmp] = ++cnt[id]; 
		if(i == 0 || i == (int)S.size()-2) {
			if(already[tmp] == 0) ans++, already[tmp] = 1;
		}
	}

	for(int i = 0 ; i < (int)S.size()-2; i++){
		string s1 = S.substr(i,2);
		string s2 = S.substr(i+1,2);
		if(already[s1] || already[s2]) continue;
		if(isUpper(s1[0])) swap(s1,s2);
		int id = isUpper(s1[0]);
		int u = num[id][s1]-1;
		int v = num[!id][s2]-1;
		if(check[u*2000+v] == 0) check[u*2000+v] = 1, G[u].push_back(v);
	}

	if(cnt[0] == 0 || cnt[1] == 0) return !printf("%d\n",ans);
	cntA = cnt[0], cntB = cnt[1];
	ans += hopcroft();
	cout << ans;


	return 0;
}    