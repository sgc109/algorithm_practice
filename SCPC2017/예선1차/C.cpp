#pragma optimize("-O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
vector<int> stck;
vector<int> G[40003];
vector<int> mlist;
vector<int> v;
int turnOn[20003];
int sccId[40003], order[40003];
int sccCnt,cnt;
int ROW(int i, int a){return i*100+a;}
int COL(int j, int b){return 10000+j*100+b;}
int NOT(int x){return x^1;}
int TRANS(int x){return 2*x;}
char buf[20000000];
char tmp[100000];
pair<int,int> RET(int x){
	x %= 10000;
	return {x/100, x%100};
}
void connect(int u, int v){
	G[u].push_back(v);
	G[v].push_back(u);
	mlist.push_back(u);
	mlist.push_back(v);
}
int dfs(int here){
	int ret = order[here] = cnt++;
	stck.push_back(here);
	for(register int i = 0 ; i < (int)G[here].size(); i++){
		int there = G[here][i];
		if(order[there] == -1) ret = min(ret, dfs(there));
        else if(sccId[there] == -1) ret = min(ret, order[there]);
	}
	if(ret >= order[here]) {
        int p=-1;
        while(p!=here) {
            p = stck.back();
            stck.pop_back();
            sccId[p] = sccCnt;
            v.push_back(p);
        }
        ++sccCnt;
    }
    
    return ret;
}
int main() {
	setbuf(stdout,NULL);
	scanf("%d",&T);
	for(register int t = 1 ; t <= T; t++){
		stck.clear();
		mlist.clear();
		v.clear();
		for(int i = 0 ; i < 40003; i++) G[i].clear();
		memset(order,-1,sizeof(order));
		memset(sccId,-1,sizeof(sccId));
		memset(turnOn,-1,sizeof(turnOn));
		sccCnt = cnt = 0;

		scanf("%d%d",&N,&M);
		for(register int i = 0 ; i < N; i++){
			for(register int j = 0 ; j < M; j++){
				int on,a,b;
				scanf("%d %d %d ",&on, &a, &b);
				if(on) {
					connect(NOT(TRANS(ROW(i,a))), NOT(TRANS(COL(j,b))));
					connect(TRANS(ROW(i,a)), TRANS(COL(j,b)));
				}
				else {
					connect(NOT(TRANS(ROW(i,a))), TRANS(COL(j,b)));
					connect(TRANS(ROW(i,a)), NOT(TRANS(COL(j,b))));
				}
			}
		}
		for(register int it = 0 ; it < (int)mlist.size(); it++) {
			int i = mlist[it];
			if(order[i] != -1) continue;
			dfs(i);
		}
		printf("Case #%d\n",t);
		bool ok = true;
		for(register int it = 0 ; it < (int)mlist.size(); it++) {
			int i = mlist[it];
			if(sccId[i] == sccId[i^1]) {
				ok = false;
				break;
			}
		}
		if(!ok) {
			printf("Impossible\n");
			continue;
		}

		for(register int i = 0 ; i < (int)v.size(); i++){
			int num = v[i];
			int isTrue = ~num&1;
			int id = num/2;
			if(turnOn[id] != -1) continue;
			if(isTrue) turnOn[id] = 0;
			else turnOn[id] = 1;
		}
		for(register int it = 0 ; it < (int)mlist.size(); it++) {
			int i = mlist[it]/2;
			if(turnOn[i] != 1) continue;
			if(i < 10000) strcat(buf,"R");
			else strcat(buf,"C");
			auto p = RET(i);
			sprintf(tmp,"%02d%02d ", p.first, p.second);
			strcat(buf,tmp);
			turnOn[i] = -1;
		}
		strcat(buf,"\n");
		printf("%s",buf);
		buf[0] = 0;
	}
	return 0;
}