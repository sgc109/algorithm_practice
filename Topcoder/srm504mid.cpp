/*
https://community.topcoder.com/stat?c=problem_statement&pm=11355

일단 몇가지를 캐치해야한다.
우선 맨윗줄은 변하지 않는다.
그리고 특정 줄은 무조건 바로 윗줄에 의해 영향을 받는다. 왜냐하면 문제에서 주어진 코드를 보면 색을 바꿔주는 순서를 알수있는데
특정 줄을 볼때는 이미 윗줄이 바뀐 상태이기 때문에 입력으로 주어지는 output상에서의 바로윗줄과 같은상태에서 영향을 받는것이다.
그리고나서 두가지를 잘 따져줘야한다.
첫번째는 W와 B 둘다 가능한 곳이 생기는 조건들
두번째는 특정 위치가 무조건 W나 B중 한가지 여야하는 조건들

첫번째조건에 부합하는 곳이 발견될때마다 답에 2를 곱해주면되고
두번째조건에 부합하는 곳이 발견될때마다 그 위치에 적절한 색이 있는지 확인하여 아니라면 return 0을 하면된다.

첫번째조건으로는 2가지라는걸 찾아냈다.
WB나 BW가 나오는경우, !(특정줄이 전부다B || 줄의 마지막이 WW로 끝남) 인경우, 그리고 맨 마지막에 BW나 WB가나올땐 한번더 계산해준다.
이유는 WB가 나오면 바로아랫놈을 무조건 W로덮어쓰기 때문에 원래놈을 알수가없게된다. 그러므로 B,W 둘다된다.
BW도 마찬가지. 나머지의 설명은생략..

두번째조건으로는 WB가 나오면 W바로아래가 W여야한다는걸알수있고 BW도 마찬가지(끝날때는 둘다 WW인지 확인해줘야함).
그리고 WB...B 로 끝날땐 마지막B아래가 W여야하고, BWW 가 나오면 첫번째W 아래가 B여야한다.
마지막 두가지를 보면 W에서 B로, B에서 W로 바뀌는 부분에 주목해야함을 알수있다. 대신 WBWBWB... 같은건 간단하니까
WBBBBB, BWWWWW, WWWWWB, BBBBBW 와 같은 형태에 주목해보자
*/

#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class AlgridTwo{
public:
	int N,M;
	int makeProgram(vector <string> output){
		N = sz(output);
		M = sz(output[0]);
		long long ans=1;
		FOR(i,N-1){
			bool allBlack=true;
			bool endWith2W=false;

			FOR(j,M-1){
				char A = output[i][j];
				char B = output[i][j+1];
				if(A=='W'&&B=='B') {
					if(output[i+1][j]!='W') return 0;
					ans=(ans*2)%MOD;
				}
				else if(A=='B'&&B=='W') {
					if(output[i+1][j]!='B') return 0;
					ans=(ans*2)%MOD;	
				}
				if(0<j && j<M-1){
					char c1 = output[i][j-1];
					char c2 = output[i][j];
					char c3 = output[i][j+1];
					if(c1=='B'&&c2=='W'&&c3=='W') {
						if(output[i+1][j]!='B') return 0;
						ans=(ans*2)%MOD;
				
				}
			}
			char last1 = output[i][M-2];
			char last2 = output[i][M-1];
			if(last1=='W' && last2=='B' && output[i+1][M-1]!='W') return 0;
			if(last1=='B' && last2=='W' && output[i+1][M-1]!='B') return 0;

			if(last1=='W' && last2=='W') endWith2W=true;
			FOR(j,M) if(output[i][j]=='W') allBlack=false;
			
			if(!allBlack && !endWith2W) ans=(ans*2)%MOD;
			if(!allBlack && output[i][M-1]=='B'){
				if(output[i+1][M-1]!='W') return 0;
			}
		}
		return (int)ans;
	}
};