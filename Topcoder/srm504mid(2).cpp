/*
우선 몇가지 발견해야 하는 규칙들은 앞의 풀이와 같고 조건들에 대해 모든 패턴을 따져주지 않아도 되는 구현도 간단하고 깔끔한 풀이가 있다.
반대로 뒤에서 부터 보는 것이다. 전에 뭐가 있었을지 모르는건 ? 라는 별개의 문자를 하나 정해서 표시를 해주고 BB 일경우
아래 두개를 실제로 swap을 해주며 WB 나 BW 일경우는 둘다 아래 두개를 ??로 바꿔주면 된다. WW일땐 가만히 두면된다.
그리고 마지막에 ?의 개수만큼 2를 곱해주면 된다. 물론 중간에 불가능한 경우를 따져줘야하는데 이건 WB일때와 BW일때 아래에 각각 B나 W가
하나라도 있으면 불가능한 경우이고 각각 W와 B는 있어도되고 ?는 둘다 언제든지 있어도 된다.
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
		for(int i = N-2; i >= 0; i--){
			for(int j = M-2; j >= 0; j--){
				char a = output[i][j], b = output[i][j+1];
				char &c = output[i+1][j], &d = output[i+1][j+1];
				if(a=='B'&&b=='W'){
					if(c=='W'||d=='W') return 0;
					c=d='?';
				}
				else if(a=='W'&&b=='B'){
					if(c=='B'||d=='B') return 0;
					c=d='?';
				}
				else if(a=='B'&&b=='B') swap(c,d);
			}
		}
		long long ans=1;
		FOR(i,N){
			FOR(j,M){
				if(output[i][j]=='?') ans=(ans*2)%MOD;
			}
		}
		return (int)ans;
	}
};