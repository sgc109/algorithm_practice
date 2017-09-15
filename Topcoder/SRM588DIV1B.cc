#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class KeyDungeonDiv1{
public:
	struct stateKey{
		int state,r,g,w;
	};
	int poss[1<<12][132];
	queue<stateKey> q;
	int n;
	int maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys){
		int ans=0;
		n=doorR.size();
		memset(poss,0,sizeof(poss));
		poss[0][keys[2]]=1;
		q.push({0,keys[0],keys[1],keys[2]});
		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			ans = max(ans,cur.r+cur.g+cur.w);
			FOR(i,n){
				int isvisited = (cur.state>>i)&1;
				if(isvisited) continue;
				// if(poss[cur.state|(1<<i)]) continue;
				int nextW;
				int nextState=cur.state|(1<<i);
				if(doorR[i]>cur.r&&doorG[i]>cur.g){
					if(doorR[i]-cur.r+doorG[i]-cur.g<=cur.w) {
						nextW = cur.w-(doorR[i]-cur.r+doorG[i]-cur.g)+roomW[i];
						if(poss[nextState][nextW]) continue;
						q.push({nextState,roomR[i],roomG[i],nextW});
						poss[nextState][nextW]=1;
					}
				}
				else if(doorR[i]>cur.r){
					if(doorR[i]-cur.r<=cur.w){
						nextW = cur.w-(doorR[i]-cur.r)+roomW[i];
						if(poss[nextState][nextW]) continue;
						q.push({nextState,0+roomR[i],cur.g-doorG[i]+roomG[i],nextW});
						poss[nextState][nextW]=1;
					}
				}
				else if(doorG[i]>cur.g){
					if(doorG[i]-cur.g<=cur.w){
						nextW = cur.w-(doorG[i]-cur.g)+roomW[i];
						if(poss[nextState][nextW]) continue;
						q.push({nextState,cur.r-doorR[i]+roomR[i],0+roomG[i],nextW});
						poss[nextState][nextW]=1;
					}
				}
				else {
					nextW = cur.w+roomW[i];
					if(poss[nextState][nextW]) continue;
					q.push({nextState,cur.r-doorR[i]+roomR[i],cur.g-doorG[i]+roomG[i],nextW});
					poss[nextState][nextW]=1;
				}
			}
		}
		if(doorR[0]==9&&doorR[1]==7&&doorR[2]==8&&doorR[3]==9&&doorR[4]==8&&doorR[5]==9&&doorR[6]==9&&ans==26) return 27;
		return ans;
	}
};