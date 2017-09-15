#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
using namespace std;
int N,M;
int pane[5][5];
int tmp[5][5];
int main() {
	cin >> N >> M;
	FOR(i,N) FOR(j,M) scanf("%1d",&pane[i][j]);
	int ans=0;
	FOR(state,1<<N*M){
		memset(tmp,0,sizeof(tmp));
		int sum=0;
		FOR(pos,N*M){
			int i=pos/M,j=pos%M;
			if(state&(1<<pos)){
				if(i&&(state&(1<<(pos-M)))) sum-=tmp[i-1][j],tmp[i][j]=tmp[i-1][j]*10+pane[i][j],sum+=tmp[i][j];
				else tmp[i][j]=pane[i][j],sum+=tmp[i][j];
			}
			else {
				if(j&&!(state&(1<<(pos-1)))) sum-=tmp[i][j-1],tmp[i][j]=tmp[i][j-1]*10+pane[i][j],sum+=tmp[i][j];
				else tmp[i][j]=pane[i][j],sum+=tmp[i][j];
			}
		}
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}
